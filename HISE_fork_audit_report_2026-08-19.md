# HISE Fork Audit

Date: 2026-08-19

Scope:
- Compare `HISE copy/develop` against the current `HISE/develop`
- Focus on Rick-authored commits
- Separate meaningful code changes from likely noise

## Summary

The backup repo at `/Users/rick/Documents/GitHub/HISE copy/` reflects an older `develop` tip than the current repo at `/Users/rick/Documents/GitHub/HISE`.

However, the Rick-authored commits visible in the backup do not appear to be lost from the current repo entirely. They are either:
- still present on current `develop`
- or still reachable on side refs / local branches such as `backup/develop-pre-sync-2026-08-04` and `new`

For the specific hardcoded / `extra_mod` issue being debugged in Oi-Grandad, the relevant upstream fixes are still present in the current fork:
- `dc5bb89e6` `fixed extra_mods not being initialised correctly in FX plugins`
- `716d71323` `fixed non-dense parameter indexes at Arpeggiator & hardcoded modules`

## Rick-Authored Commits Seen In Backup History

Visible on `HISE copy/develop`:
- `2b2676aec` `changes`
- `ac07dc3fc` `v`

## Rick-Authored Commits Seen In Current Repo

Visible in the current repo around the same period:
- `ac07dc3fc` `v`
- `2b2676aec` `changes`
- `c2bb4a5bb` `headers`
- `3118ee3c0` `rest`
- `fdfd304c3` `lin edits`
- `de5a95e91` `clean`
- `8b95f41f9` `changes`
- `015ea07c7` `preset fix`

## Where Those Older Commits Ended Up

In the current repo:
- `ac07dc3fc` is still reachable via `backup/develop-pre-sync-2026-08-04`
- `2b2676aec` is still reachable via branch `new`

So the older line from the backup was moved off `develop`, but not obviously deleted.

## Meaningful Vs Noise

### Likely meaningful

`ac07dc3fc` `v`
- Broad REST/API/editor/build sweep
- touched:
  - `hi_backend/backend/ai_tools/*`
  - `hi_core/hi_dsp/ProcessorMetadataRegistry.*`
  - `hi_scripting/scripting/ScriptProcessorModules.cpp`
  - `hi_scripting/scripting/api/ScriptingApiContent.cpp`
  - `hi_scripting/scripting/api/ScriptingApiObjects.cpp`
  - standalone project files
  - scriptnode database blob

Assessment:
- Mixed commit
- contains real feature / tooling work
- also contains a lot of generated and version/hash churn

`2b2676aec` `changes`
- touched:
  - `hi_dsp_library/node_api/nodes/Container_Split.h`
  - `hi_dsp_library/node_api/nodes/duplicate.h`
  - `hi_scripting/scripting/api/ScriptingApiContent.cpp`
  - `hi_snex/snex_cpp_builder/snex_jit_ValueTreeBuilder.cpp`
  - standalone project files
  - scriptnode database blob

Assessment:
- meaningful code changes
- especially relevant if you care about scriptnode / content restore / node behavior

`3118ee3c0` `rest`
- small REST server change
- touched:
  - `hi_backend/backend/ai_tools/RestServer.cpp`
  - `hi_backend/backend/ai_tools/RestServer.h`

Assessment:
- meaningful if you rely on REST behavior

`8b95f41f9` `changes`
- touched:
  - `Container_Split.h`
  - `duplicate.h`
  - `ScriptingApiContent.cpp`
  - `snex_jit_ValueTreeBuilder.cpp`
  - `projects/standalone/JuceLibraryCode/AppConfig.h`

Assessment:
- meaningful
- this looks like the current-line successor to part of the earlier `2b2676aec` work

`015ea07c7` `preset fix`
- touched:
  - `ScriptingApiContent.cpp`
  - standalone project files
  - scriptnode database blob

Assessment:
- meaningful if the waveform/content restore fix matters to you

### Likely noise or mostly generated

`fdfd304c3` `lin edits`
- only scriptnode database blob changed

`de5a95e91` `clean`
- only scriptnode database blob changed

`c2bb4a5bb` `headers`
- mixed bag
- includes `AGENTS.md` and major generated project/blob churn
- may still contain meaningful standalone header cleanup, but needs targeted review before relying on the commit title

## Crash-Relevant Conclusion

For the Oi-Grandad standalone crash investigation:
- I do not see evidence that a key pre-sync Rick-authored hardcoded / `extra_mod` fix was lost
- the current repo still contains the upstream fixes most likely to matter there
- the current fork does not appear to be missing a known Rick-authored commit that directly explains the crash

## Broader Fork Preservation Conclusion

For your wider concern about custom hacks and fixes:
- there probably is still value in a later full audit
- not because commits are missing entirely
- but because some meaningful work is no longer on `develop` and is easy to forget about

That later audit should classify Rick-authored changes by subsystem:
- REST/API
- scripting/content restore
- scriptnode/node API
- standalone/export/build
- metadata/hardcoded behavior

## Recommended Follow-Up Later

When you return to this:
1. Review `ac07dc3fc` and `2b2676aec` in detail first.
2. Compare them against `8b95f41f9` and `015ea07c7`.
3. For each meaningful change, decide:
   - already preserved on current `develop`
   - preserved differently
   - only present on backup refs and should be cherry-picked or re-applied

## Paths

Compared repos:
- `/Users/rick/Documents/GitHub/HISE`
- `/Users/rick/Documents/GitHub/HISE copy`

Report source copy in workspace:
- `/Users/rick/Documents/GitHub/Oi-Grandad/HISE_fork_audit_report_2026-08-19.md`
