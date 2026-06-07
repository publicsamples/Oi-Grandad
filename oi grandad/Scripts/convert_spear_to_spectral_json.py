#!/usr/bin/env python3

import json
import sys
from pathlib import Path


def parse_spear_text(path: Path) -> dict:
    lines = path.read_text(encoding="utf-8").splitlines()

    partial_count = 0
    frame_count = 0
    frames = []
    in_frame_data = False
    hop_time = 0.0
    last_time = None

    for raw_line in lines:
        line = raw_line.strip()

        if not line:
            continue

        if line.startswith("partials-count "):
            partial_count = int(line.split()[1])
            continue

        if line.startswith("frame-count "):
            frame_count = int(line.split()[1])
            continue

        if line == "frame-data":
            in_frame_data = True
            continue

        if not in_frame_data:
            continue

        parts = line.split()
        if len(parts) < 2:
            continue

        time_seconds = float(parts[0])
        point_count = int(parts[1])

        frame = {
            "time": time_seconds,
            "partials": [],
        }

        base = 2
        for i in range(point_count):
            k = base + i * 3
            if k + 2 >= len(parts):
                break

            frame["partials"].append(
                {
                    "id": int(parts[k]),
                    "frequency": float(parts[k + 1]),
                    "amplitude": float(parts[k + 2]),
                }
            )

        frames.append(frame)

        if last_time is not None and hop_time == 0.0:
            hop_time = time_seconds - last_time

        last_time = time_seconds

    duration_seconds = frames[-1]["time"] if frames else 0.0

    return {
        "version": 1,
        "format": "spear-partials-v1",
        "sourceFile": str(path),
        "sampleRate": 44100,
        "durationSeconds": duration_seconds,
        "rootHz": 220.0,
        "hopTime": hop_time,
        "timedomain": "seconds",
        "frameCount": frame_count or len(frames),
        "partialCount": partial_count,
        "frames": frames,
    }


def main(argv: list[str]) -> int:
    if len(argv) != 3:
        print("usage: convert_spear_to_spectral_json.py <input.txt> <output.json>", file=sys.stderr)
        return 2

    input_path = Path(argv[1])
    output_path = Path(argv[2])

    data = parse_spear_text(input_path)
    output_path.write_text(json.dumps(data, indent=2), encoding="utf-8")

    print(f"wrote {output_path}")
    print(f"frames={data['frameCount']} partials={data['partialCount']} hopTime={data['hopTime']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
