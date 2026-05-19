# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# Cap parallel jobs to physical core count (prevents OOM on template-heavy codebases).
# Override by invoking make with an explicit -j flag, e.g. `make -j8`.
ifeq ($(origin JUCE_JOBS_CAPPED),undefined)
  export JUCE_JOBS_CAPPED := 1
  MAKEFLAGS += -j$(shell sysctl -n hw.physicalcpu) -l $(shell sysctl -n hw.physicalcpu)
endif

# build with "V=1" for verbose builds
ifeq ($(V), 1)
V_AT =
else
V_AT = @
endif

# (disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

.DEFAULT_GOAL := all

ifndef STRIP
  STRIP=strip
endif

ifndef AR
  AR=ar
endif

ifndef CONFIG
  CONFIG=Debug
endif

JUCE_ARCH_LABEL := $(shell uname -m)

ifeq ($(CONFIG),Debug)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Debug
  JUCE_OUTDIR := build/Debug

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -arch x86_64
  endif

  JUCE_PCH     :=
  JUCE_PCH_INC :=

  JUCE_CPPFLAGS := $(DEPFLAGS)  "-DDEBUG=1" "-D_DEBUG=1" "-DHISE_NUM_PLUGIN_CHANNELS=10" "-DHISE_MACROS_ARE_PLUGIN_PARAMETERS=1" "-DHISE_NUM_MACROS=8" "-DHISE_INCLUDE_LORIS=0" "-DJUCER_MACOSX_MAKE_28416E59=1" "-DJUCE_APP_VERSION=2.3.5" "-DJUCE_APP_VERSION_HEX=0x20305" -I/Users/rick/Documents/GitHub/HISE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I/Users/rick/Documents/GitHub/HISE/tools/SDK/VST3\ SDK -I../../JuceLibraryCode -I/Users/rick/Documents/GitHub/HISE -I/Users/rick/Documents/GitHub/HISE/JUCE/modules -I/Users/rick/Documents/GitHub/HISE/tools/faust/include $(CPPFLAGS)

  JUCE_CPPFLAGS_VST3 :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=1" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0"
  JUCE_CFLAGS_VST3 := -fvisibility=hidden
  JUCE_LDFLAGS_VST3 := -bundle
  JUCE_BUNDLEDIR_VST3 := oi\ grandad\ Debug.vst3
  JUCE_TARGET_VST3 := oi\ grandad\ Debug.vst3/Contents/MacOS/oi\ grandad\ Debug
  JUCE_PLIST_VST3 := Info-VST3-Debug.plist
  JUCE_STRIPCMD_VST3 := true

  JUCE_CPPFLAGS_AU :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=0" "-DJucePlugin_Build_AU=1" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0"
  JUCE_CFLAGS_AU := -fvisibility=hidden
  JUCE_LDFLAGS_AU := -bundle
  JUCE_BUNDLEDIR_AU := oi\ grandad\ Debug.component
  JUCE_TARGET_AU := oi\ grandad\ Debug.component/Contents/MacOS/oi\ grandad\ Debug
  JUCE_PLIST_AU := Info-AU-Debug.plist
  JUCE_STRIPCMD_AU := true

  JUCE_CPPFLAGS_SHARED_CODE :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=1" "-DJucePlugin_Build_AU=1" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0" "-DJUCE_SHARED_CODE=1"
  JUCE_CFLAGS_SHARED_CODE := -fvisibility=hidden
  JUCE_TARGET_SHARED_CODE := liboi\ grandad\ Debug.a
  JUCE_STRIPCMD_SHARED_CODE := true

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0 -isysroot $(shell xcrun --sdk macosx --show-sdk-path) -mmacosx-version-min=11.0 -Wno-reorder -Wno-inconsistent-missing-override  -faligned-allocation -ffp-contract=off $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 -stdlib=libc++ $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -fvisibility=hidden -stdlib=libc++ -mmacosx-version-min=11.0 -Wl,-ld_new -framework Accelerate -framework CoreAudio -framework CoreMIDI -framework AudioToolbox -framework QuartzCore -framework CoreAudioKit -framework DiscRecording -framework Cocoa -framework Foundation -framework IOKit -framework Carbon -framework WebKit -framework OpenGL $(LDFLAGS)

  OBJECTS_VST3 := \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_VST3_dd633589.o \

  OBJECTS_AU := \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_AU_df61cc30.o \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_AU_1_386633b0.o \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_AU_2_3866a80f.o \

  OBJECTS_SHARED_CODE := \
    $(JUCE_OBJDIR)/include_hi_scripting_01_6ad431f1.o \
    $(JUCE_OBJDIR)/include_hi_tools_01_aabcc84d.o \
    $(JUCE_OBJDIR)/include_hi_scripting_03_6af060f3.o \
    $(JUCE_OBJDIR)/CopyProtection_c183dcb7.o \
    $(JUCE_OBJDIR)/Plugin_124bbd3c.o \
    $(JUCE_OBJDIR)/PresetData_a83b9832.o \
    $(JUCE_OBJDIR)/factory_3d20f030.o \
    $(JUCE_OBJDIR)/RNBO_b0a3e5ed.o \
    $(JUCE_OBJDIR)/BinaryData_ce4232d4.o \
    $(JUCE_OBJDIR)/include_hi_core_ff8d8d87.o \
    $(JUCE_OBJDIR)/include_hi_core_02_bf2cb0c4.o \
    $(JUCE_OBJDIR)/include_hi_core_03_bf3ac845.o \
    $(JUCE_OBJDIR)/include_hi_core_04_bf48dfc6.o \
    $(JUCE_OBJDIR)/include_hi_core_05_bf56f747.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_01_6050d6b.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_02_61324ec.o \
    $(JUCE_OBJDIR)/include_hi_frontend_f98d5f69.o \
    $(JUCE_OBJDIR)/include_hi_lac_15d99830.o \
    $(JUCE_OBJDIR)/include_hi_lac_02_7a39397b.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_3f7c6c10.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_1_40582c65.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_2_406643e6.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_3_40745b67.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_4_408272e8.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_5_40908a69.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_6_409ea1ea.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_7_40acb96b.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_8_40bad0ec.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_9_40c8e86d.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_10_cab14735.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_11_cabf5eb6.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_12_cacd7637.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_13_cadb8db8.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_14_cae9a539.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_15_caf7bcba.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_16_cb05d43b.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_17_cb13ebbc.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_18_cb22033d.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_19_cb301abe.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_20_cc661fd4.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_21_cc743755.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_22_cc824ed6.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_23_cc906657.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_24_cc9e7dd8.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_25_ccac9559.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_26_ccbaacda.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_27_ccc8c45b.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_28_ccd6dbdc.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_29_cce4f35d.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_30_ce1af873.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_31_ce290ff4.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_32_ce372775.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_33_ce453ef6.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_34_ce535677.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_35_ce616df8.o \
    $(JUCE_OBJDIR)/include_hi_scripting_02_6ae24972.o \
    $(JUCE_OBJDIR)/include_hi_scripting_04_6afe7874.o \
    $(JUCE_OBJDIR)/include_hi_snex_9e91422d.o \
    $(JUCE_OBJDIR)/include_hi_snex_60_41e20b2d.o \
    $(JUCE_OBJDIR)/include_hi_snex_61_41e20eee.o \
    $(JUCE_OBJDIR)/include_hi_snex_62_51a830ef.o \
    $(JUCE_OBJDIR)/include_hi_streaming_6963df44.o \
    $(JUCE_OBJDIR)/include_hi_tools_02_aacadfce.o \
    $(JUCE_OBJDIR)/include_hi_tools_03_aad8f74f.o \
    $(JUCE_OBJDIR)/include_hi_zstd_1_4e813b40.o \
    $(JUCE_OBJDIR)/include_hi_zstd_2_4e81af9f.o \
    $(JUCE_OBJDIR)/include_hi_zstd_3_4e8223fe.o \
    $(JUCE_OBJDIR)/include_juce_audio_basics_f3f20619.o \
    $(JUCE_OBJDIR)/include_juce_audio_devices_faf00a61.o \
    $(JUCE_OBJDIR)/include_juce_audio_formats_dfad2b82.o \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_utils_e32edaee.o \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_VST_utils_28d674fd.o \
    $(JUCE_OBJDIR)/include_juce_audio_processors_f006347d.o \
    $(JUCE_OBJDIR)/include_juce_audio_processors_headless_9db5c527.o \
    $(JUCE_OBJDIR)/include_juce_audio_utils_a20d6a0d.o \
    $(JUCE_OBJDIR)/include_juce_core_732cd068.o \
    $(JUCE_OBJDIR)/include_juce_cryptography_150e32fb.o \
    $(JUCE_OBJDIR)/include_juce_data_structures_a0a8d560.o \
    $(JUCE_OBJDIR)/include_juce_dsp_58374bb4.o \
    $(JUCE_OBJDIR)/include_juce_events_be72526e.o \
    $(JUCE_OBJDIR)/include_juce_graphics_398d297c.o \
    $(JUCE_OBJDIR)/include_juce_gui_basics_17deb37e.o \
    $(JUCE_OBJDIR)/include_juce_gui_extra_7f6ac849.o \
    $(JUCE_OBJDIR)/include_juce_opengl_191d3b18.o \
    $(JUCE_OBJDIR)/include_juce_osc_f3df604d.o \
    $(JUCE_OBJDIR)/include_juce_product_unlocking_2d7fc747.o \
    $(JUCE_OBJDIR)/include_melatonin_blur_455ca9bb.o \

  CLEANCMD = rm -rf $(JUCE_OUTDIR) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release
  JUCE_OUTDIR := build/Release

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -arch x86_64
  endif

  JUCE_PCH     :=
  JUCE_PCH_INC :=

  JUCE_CPPFLAGS := $(DEPFLAGS)  "-DNDEBUG=1" "-DHISE_NUM_PLUGIN_CHANNELS=10" "-DHISE_MACROS_ARE_PLUGIN_PARAMETERS=1" "-DHISE_NUM_MACROS=8" "-DHISE_INCLUDE_LORIS=0" "-DJUCER_MACOSX_MAKE_28416E59=1" "-DJUCE_APP_VERSION=2.3.5" "-DJUCE_APP_VERSION_HEX=0x20305" -I/Users/rick/Documents/GitHub/HISE/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I/Users/rick/Documents/GitHub/HISE/tools/SDK/VST3\ SDK -I../../JuceLibraryCode -I/Users/rick/Documents/GitHub/HISE -I/Users/rick/Documents/GitHub/HISE/JUCE/modules -I/Users/rick/Documents/GitHub/HISE/tools/faust/include $(CPPFLAGS)

  JUCE_CPPFLAGS_VST3 :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=1" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0"
  JUCE_CFLAGS_VST3 := -fvisibility=hidden
  JUCE_LDFLAGS_VST3 := -bundle
  JUCE_BUNDLEDIR_VST3 := oi\ grandad.vst3
  JUCE_TARGET_VST3 := oi\ grandad.vst3/Contents/MacOS/oi\ grandad
  JUCE_PLIST_VST3 := Info-VST3-Release.plist
  JUCE_STRIPCMD_VST3 := $(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(JUCE_TARGET_VST3)

  JUCE_CPPFLAGS_AU :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=0" "-DJucePlugin_Build_AU=1" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0"
  JUCE_CFLAGS_AU := -fvisibility=hidden
  JUCE_LDFLAGS_AU := -bundle
  JUCE_BUNDLEDIR_AU := oi\ grandad.component
  JUCE_TARGET_AU := oi\ grandad.component/Contents/MacOS/oi\ grandad
  JUCE_PLIST_AU := Info-AU-Release.plist
  JUCE_STRIPCMD_AU := $(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(JUCE_TARGET_AU)

  JUCE_CPPFLAGS_SHARED_CODE :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=1" "-DJucePlugin_Build_AU=1" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0" "-DJUCE_SHARED_CODE=1"
  JUCE_CFLAGS_SHARED_CODE := -fvisibility=hidden
  JUCE_TARGET_SHARED_CODE := liboi\ grandad.a
  JUCE_STRIPCMD_SHARED_CODE := true

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -O3 -flto=thin -isysroot $(shell xcrun --sdk macosx --show-sdk-path) -mmacosx-version-min=11.0 -Wno-reorder -Wno-inconsistent-missing-override  -faligned-allocation -ffp-contract=off $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 -stdlib=libc++ $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -fvisibility=hidden -stdlib=libc++ -mmacosx-version-min=11.0 -flto=thin -Wl,-cache_path_lto,build/lto_cache -Wl,-ld_new -framework Accelerate -framework CoreAudio -framework CoreMIDI -framework AudioToolbox -framework QuartzCore -framework CoreAudioKit -framework DiscRecording -framework Cocoa -framework Foundation -framework IOKit -framework Carbon -framework WebKit -framework OpenGL $(LDFLAGS)

  OBJECTS_VST3 := \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_VST3_dd633589.o \

  OBJECTS_AU := \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_AU_df61cc30.o \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_AU_1_386633b0.o \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_AU_2_3866a80f.o \

  OBJECTS_SHARED_CODE := \
    $(JUCE_OBJDIR)/include_hi_scripting_01_6ad431f1.o \
    $(JUCE_OBJDIR)/include_hi_tools_01_aabcc84d.o \
    $(JUCE_OBJDIR)/include_hi_scripting_03_6af060f3.o \
    $(JUCE_OBJDIR)/CopyProtection_c183dcb7.o \
    $(JUCE_OBJDIR)/Plugin_124bbd3c.o \
    $(JUCE_OBJDIR)/PresetData_a83b9832.o \
    $(JUCE_OBJDIR)/factory_3d20f030.o \
    $(JUCE_OBJDIR)/RNBO_b0a3e5ed.o \
    $(JUCE_OBJDIR)/BinaryData_ce4232d4.o \
    $(JUCE_OBJDIR)/include_hi_core_ff8d8d87.o \
    $(JUCE_OBJDIR)/include_hi_core_02_bf2cb0c4.o \
    $(JUCE_OBJDIR)/include_hi_core_03_bf3ac845.o \
    $(JUCE_OBJDIR)/include_hi_core_04_bf48dfc6.o \
    $(JUCE_OBJDIR)/include_hi_core_05_bf56f747.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_01_6050d6b.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_02_61324ec.o \
    $(JUCE_OBJDIR)/include_hi_frontend_f98d5f69.o \
    $(JUCE_OBJDIR)/include_hi_lac_15d99830.o \
    $(JUCE_OBJDIR)/include_hi_lac_02_7a39397b.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_3f7c6c10.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_1_40582c65.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_2_406643e6.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_3_40745b67.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_4_408272e8.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_5_40908a69.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_6_409ea1ea.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_7_40acb96b.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_8_40bad0ec.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_9_40c8e86d.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_10_cab14735.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_11_cabf5eb6.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_12_cacd7637.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_13_cadb8db8.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_14_cae9a539.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_15_caf7bcba.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_16_cb05d43b.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_17_cb13ebbc.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_18_cb22033d.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_19_cb301abe.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_20_cc661fd4.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_21_cc743755.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_22_cc824ed6.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_23_cc906657.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_24_cc9e7dd8.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_25_ccac9559.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_26_ccbaacda.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_27_ccc8c45b.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_28_ccd6dbdc.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_29_cce4f35d.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_30_ce1af873.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_31_ce290ff4.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_32_ce372775.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_33_ce453ef6.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_34_ce535677.o \
    $(JUCE_OBJDIR)/include_hi_rlottie_35_ce616df8.o \
    $(JUCE_OBJDIR)/include_hi_scripting_02_6ae24972.o \
    $(JUCE_OBJDIR)/include_hi_scripting_04_6afe7874.o \
    $(JUCE_OBJDIR)/include_hi_snex_9e91422d.o \
    $(JUCE_OBJDIR)/include_hi_snex_60_41e20b2d.o \
    $(JUCE_OBJDIR)/include_hi_snex_61_41e20eee.o \
    $(JUCE_OBJDIR)/include_hi_snex_62_51a830ef.o \
    $(JUCE_OBJDIR)/include_hi_streaming_6963df44.o \
    $(JUCE_OBJDIR)/include_hi_tools_02_aacadfce.o \
    $(JUCE_OBJDIR)/include_hi_tools_03_aad8f74f.o \
    $(JUCE_OBJDIR)/include_hi_zstd_1_4e813b40.o \
    $(JUCE_OBJDIR)/include_hi_zstd_2_4e81af9f.o \
    $(JUCE_OBJDIR)/include_hi_zstd_3_4e8223fe.o \
    $(JUCE_OBJDIR)/include_juce_audio_basics_f3f20619.o \
    $(JUCE_OBJDIR)/include_juce_audio_devices_faf00a61.o \
    $(JUCE_OBJDIR)/include_juce_audio_formats_dfad2b82.o \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_utils_e32edaee.o \
    $(JUCE_OBJDIR)/include_juce_audio_plugin_client_VST_utils_28d674fd.o \
    $(JUCE_OBJDIR)/include_juce_audio_processors_f006347d.o \
    $(JUCE_OBJDIR)/include_juce_audio_processors_headless_9db5c527.o \
    $(JUCE_OBJDIR)/include_juce_audio_utils_a20d6a0d.o \
    $(JUCE_OBJDIR)/include_juce_core_732cd068.o \
    $(JUCE_OBJDIR)/include_juce_cryptography_150e32fb.o \
    $(JUCE_OBJDIR)/include_juce_data_structures_a0a8d560.o \
    $(JUCE_OBJDIR)/include_juce_dsp_58374bb4.o \
    $(JUCE_OBJDIR)/include_juce_events_be72526e.o \
    $(JUCE_OBJDIR)/include_juce_graphics_398d297c.o \
    $(JUCE_OBJDIR)/include_juce_gui_basics_17deb37e.o \
    $(JUCE_OBJDIR)/include_juce_gui_extra_7f6ac849.o \
    $(JUCE_OBJDIR)/include_juce_opengl_191d3b18.o \
    $(JUCE_OBJDIR)/include_juce_osc_f3df604d.o \
    $(JUCE_OBJDIR)/include_juce_product_unlocking_2d7fc747.o \
    $(JUCE_OBJDIR)/include_melatonin_blur_455ca9bb.o \

  CLEANCMD = rm -rf $(JUCE_OUTDIR) $(JUCE_OBJDIR)
endif

.PHONY: clean all strip VST3 AU

all : VST3 AU

VST3 : $(JUCE_OUTDIR)/$(JUCE_TARGET_VST3)
AU : $(JUCE_OUTDIR)/$(JUCE_TARGET_AU)


$(JUCE_OUTDIR)/$(JUCE_TARGET_VST3) : $(OBJECTS_VST3) $(RESOURCES) $(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE)
	@echo Linking "oi grandad - VST3"
	-$(V_AT)mkdir -p $(JUCE_BINDIR)
	-$(V_AT)mkdir -p $(JUCE_LIBDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_VST3)/Contents/MacOS
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_VST3)/Contents/Resources
	$(V_AT)$(CXX) -o $(JUCE_OUTDIR)/$(JUCE_TARGET_VST3) $(OBJECTS_VST3) $(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE) $(JUCE_LDFLAGS) $(JUCE_LDFLAGS_VST3) $(RESOURCES) $(TARGET_ARCH)
	-$(V_AT)cp $(JUCE_PLIST_VST3) $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_VST3)/Contents/Info.plist
	-$(V_AT)printf "BNDL????" > $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_VST3)/Contents/PkgInfo
	-$(V_AT)[ -f Icon.icns ] && cp Icon.icns $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_VST3)/Contents/Resources/ || true
	-$(V_AT)$(JUCE_STRIPCMD_VST3)
ifneq ($(JUCE_VST3DESTDIR),)
	-$(V_AT)mkdir -p $(JUCE_VST3DESTDIR)
	-$(V_AT)cp -R $(JUCE_COPYCMD_VST3)/
endif

$(JUCE_OUTDIR)/$(JUCE_TARGET_AU) : $(OBJECTS_AU) $(RESOURCES) $(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE)
	@echo Linking "oi grandad - AU"
	-$(V_AT)mkdir -p $(JUCE_BINDIR)
	-$(V_AT)mkdir -p $(JUCE_LIBDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_AU)/Contents/MacOS
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_AU)/Contents/Resources
	$(V_AT)$(CXX) -o $(JUCE_OUTDIR)/$(JUCE_TARGET_AU) $(OBJECTS_AU) $(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE) $(JUCE_LDFLAGS) $(JUCE_LDFLAGS_AU) $(RESOURCES) $(TARGET_ARCH)
	-$(V_AT)cp $(JUCE_PLIST_AU) $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_AU)/Contents/Info.plist
	-$(V_AT)printf "BNDL????" > $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_AU)/Contents/PkgInfo
	-$(V_AT)[ -f Icon.icns ] && cp Icon.icns $(JUCE_OUTDIR)/$(JUCE_BUNDLEDIR_AU)/Contents/Resources/ || true
	-$(V_AT)$(JUCE_STRIPCMD_AU)
ifneq ($(JUCE_AUDESTDIR),)
	-$(V_AT)mkdir -p $(JUCE_AUDESTDIR)
	-$(V_AT)cp -R $(JUCE_COPYCMD_AU)/
endif

$(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE) : $(OBJECTS_SHARED_CODE) $(RESOURCES)
	@echo Linking "oi grandad - Shared Code"
	-$(V_AT)mkdir -p $(JUCE_BINDIR)
	-$(V_AT)mkdir -p $(JUCE_LIBDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)
	$(V_AT)$(AR) -rcs $(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE) $(OBJECTS_SHARED_CODE)
	-$(V_AT)$(JUCE_STRIPCMD_SHARED_CODE)

$(JUCE_OBJDIR)/include_juce_audio_plugin_client_VST3_dd633589.o: ../../JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_plugin_client_VST3.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) -DJUCE_SKIP_PRECOMPILED_HEADER $(JUCE_CPPFLAGS_VST3) $(JUCE_CFLAGS_VST3) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_plugin_client_AU_df61cc30.o: ../../JuceLibraryCode/include_juce_audio_plugin_client_AU.r
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_plugin_client_AU.r"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) -DJUCE_SKIP_PRECOMPILED_HEADER $(JUCE_CPPFLAGS_AU) $(JUCE_CFLAGS_AU) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_plugin_client_AU_1_386633b0.o: ../../JuceLibraryCode/include_juce_audio_plugin_client_AU_1.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_plugin_client_AU_1.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_AU) $(JUCE_CFLAGS_AU) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_plugin_client_AU_2_3866a80f.o: ../../JuceLibraryCode/include_juce_audio_plugin_client_AU_2.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_plugin_client_AU_2.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_AU) $(JUCE_CFLAGS_AU) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_scripting_01_6ad431f1.o: ../../JuceLibraryCode/include_hi_scripting_01.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_scripting_01.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_tools_01_aabcc84d.o: ../../JuceLibraryCode/include_hi_tools_01.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_tools_01.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_scripting_03_6af060f3.o: ../../JuceLibraryCode/include_hi_scripting_03.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_scripting_03.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CopyProtection_c183dcb7.o: ../../Source/CopyProtection.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling CopyProtection.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Plugin_124bbd3c.o: ../../Source/Plugin.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Plugin.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PresetData_a83b9832.o: ../../Source/PresetData.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling PresetData.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/factory_3d20f030.o: ../../../AdditionalSourceCode/nodes/factory.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling factory.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RNBO_b0a3e5ed.o: ../../../AdditionalSourceCode/nodes/RNBO.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling RNBO.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/BinaryData_ce4232d4.o: ../../JuceLibraryCode/BinaryData.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling BinaryData.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_core_ff8d8d87.o: ../../JuceLibraryCode/include_hi_core.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_core.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_core_02_bf2cb0c4.o: ../../JuceLibraryCode/include_hi_core_02.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_core_02.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_core_03_bf3ac845.o: ../../JuceLibraryCode/include_hi_core_03.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_core_03.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_core_04_bf48dfc6.o: ../../JuceLibraryCode/include_hi_core_04.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_core_04.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_core_05_bf56f747.o: ../../JuceLibraryCode/include_hi_core_05.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_core_05.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_dsp_library_01_6050d6b.o: ../../JuceLibraryCode/include_hi_dsp_library_01.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_dsp_library_01.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_dsp_library_02_61324ec.o: ../../JuceLibraryCode/include_hi_dsp_library_02.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_dsp_library_02.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_frontend_f98d5f69.o: ../../JuceLibraryCode/include_hi_frontend.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_frontend.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_lac_15d99830.o: ../../JuceLibraryCode/include_hi_lac.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_lac.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_lac_02_7a39397b.o: ../../JuceLibraryCode/include_hi_lac_02.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_lac_02.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_3f7c6c10.o: ../../JuceLibraryCode/include_hi_rlottie.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_1_40582c65.o: ../../JuceLibraryCode/include_hi_rlottie_1.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_1.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_2_406643e6.o: ../../JuceLibraryCode/include_hi_rlottie_2.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_2.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_3_40745b67.o: ../../JuceLibraryCode/include_hi_rlottie_3.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_3.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_4_408272e8.o: ../../JuceLibraryCode/include_hi_rlottie_4.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_4.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_5_40908a69.o: ../../JuceLibraryCode/include_hi_rlottie_5.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_5.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_6_409ea1ea.o: ../../JuceLibraryCode/include_hi_rlottie_6.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_6.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_7_40acb96b.o: ../../JuceLibraryCode/include_hi_rlottie_7.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_7.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_8_40bad0ec.o: ../../JuceLibraryCode/include_hi_rlottie_8.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_8.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_9_40c8e86d.o: ../../JuceLibraryCode/include_hi_rlottie_9.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_9.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_10_cab14735.o: ../../JuceLibraryCode/include_hi_rlottie_10.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_10.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_11_cabf5eb6.o: ../../JuceLibraryCode/include_hi_rlottie_11.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_11.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_12_cacd7637.o: ../../JuceLibraryCode/include_hi_rlottie_12.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_12.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_13_cadb8db8.o: ../../JuceLibraryCode/include_hi_rlottie_13.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_13.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_14_cae9a539.o: ../../JuceLibraryCode/include_hi_rlottie_14.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_14.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_15_caf7bcba.o: ../../JuceLibraryCode/include_hi_rlottie_15.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_15.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_16_cb05d43b.o: ../../JuceLibraryCode/include_hi_rlottie_16.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_16.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_17_cb13ebbc.o: ../../JuceLibraryCode/include_hi_rlottie_17.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_17.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_18_cb22033d.o: ../../JuceLibraryCode/include_hi_rlottie_18.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_18.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_19_cb301abe.o: ../../JuceLibraryCode/include_hi_rlottie_19.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_19.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_20_cc661fd4.o: ../../JuceLibraryCode/include_hi_rlottie_20.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_20.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_21_cc743755.o: ../../JuceLibraryCode/include_hi_rlottie_21.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_21.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_22_cc824ed6.o: ../../JuceLibraryCode/include_hi_rlottie_22.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_22.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_23_cc906657.o: ../../JuceLibraryCode/include_hi_rlottie_23.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_23.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_24_cc9e7dd8.o: ../../JuceLibraryCode/include_hi_rlottie_24.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_24.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_25_ccac9559.o: ../../JuceLibraryCode/include_hi_rlottie_25.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_25.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_26_ccbaacda.o: ../../JuceLibraryCode/include_hi_rlottie_26.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_26.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_27_ccc8c45b.o: ../../JuceLibraryCode/include_hi_rlottie_27.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_27.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_28_ccd6dbdc.o: ../../JuceLibraryCode/include_hi_rlottie_28.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_28.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_29_cce4f35d.o: ../../JuceLibraryCode/include_hi_rlottie_29.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_29.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_30_ce1af873.o: ../../JuceLibraryCode/include_hi_rlottie_30.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_30.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_31_ce290ff4.o: ../../JuceLibraryCode/include_hi_rlottie_31.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_31.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_32_ce372775.o: ../../JuceLibraryCode/include_hi_rlottie_32.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_32.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_33_ce453ef6.o: ../../JuceLibraryCode/include_hi_rlottie_33.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_33.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_34_ce535677.o: ../../JuceLibraryCode/include_hi_rlottie_34.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_34.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_rlottie_35_ce616df8.o: ../../JuceLibraryCode/include_hi_rlottie_35.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_rlottie_35.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_scripting_02_6ae24972.o: ../../JuceLibraryCode/include_hi_scripting_02.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_scripting_02.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_scripting_04_6afe7874.o: ../../JuceLibraryCode/include_hi_scripting_04.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_scripting_04.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_snex_9e91422d.o: ../../JuceLibraryCode/include_hi_snex.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_snex.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_snex_60_41e20b2d.o: ../../JuceLibraryCode/include_hi_snex_60.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_snex_60.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_snex_61_41e20eee.o: ../../JuceLibraryCode/include_hi_snex_61.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_snex_61.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_snex_62_51a830ef.o: ../../JuceLibraryCode/include_hi_snex_62.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_snex_62.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_streaming_6963df44.o: ../../JuceLibraryCode/include_hi_streaming.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_streaming.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_tools_02_aacadfce.o: ../../JuceLibraryCode/include_hi_tools_02.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_tools_02.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_tools_03_aad8f74f.o: ../../JuceLibraryCode/include_hi_tools_03.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_tools_03.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_zstd_1_4e813b40.o: ../../JuceLibraryCode/include_hi_zstd_1.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_zstd_1.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_zstd_2_4e81af9f.o: ../../JuceLibraryCode/include_hi_zstd_2.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_zstd_2.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_zstd_3_4e8223fe.o: ../../JuceLibraryCode/include_hi_zstd_3.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_zstd_3.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_basics_f3f20619.o: ../../JuceLibraryCode/include_juce_audio_basics.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_basics.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_devices_faf00a61.o: ../../JuceLibraryCode/include_juce_audio_devices.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_devices.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_formats_dfad2b82.o: ../../JuceLibraryCode/include_juce_audio_formats.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_formats.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_plugin_client_utils_e32edaee.o: ../../JuceLibraryCode/include_juce_audio_plugin_client_utils.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_plugin_client_utils.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) -DJUCE_SKIP_PRECOMPILED_HEADER $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_plugin_client_VST_utils_28d674fd.o: ../../JuceLibraryCode/include_juce_audio_plugin_client_VST_utils.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_plugin_client_VST_utils.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_processors_f006347d.o: ../../JuceLibraryCode/include_juce_audio_processors.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_processors.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_processors_headless_9db5c527.o: ../../JuceLibraryCode/include_juce_audio_processors_headless.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_processors_headless.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_utils_a20d6a0d.o: ../../JuceLibraryCode/include_juce_audio_utils.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_utils.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_core_732cd068.o: ../../JuceLibraryCode/include_juce_core.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_core.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_cryptography_150e32fb.o: ../../JuceLibraryCode/include_juce_cryptography.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_cryptography.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_data_structures_a0a8d560.o: ../../JuceLibraryCode/include_juce_data_structures.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_data_structures.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_dsp_58374bb4.o: ../../JuceLibraryCode/include_juce_dsp.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_dsp.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_events_be72526e.o: ../../JuceLibraryCode/include_juce_events.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_events.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_graphics_398d297c.o: ../../JuceLibraryCode/include_juce_graphics.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_graphics.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_gui_basics_17deb37e.o: ../../JuceLibraryCode/include_juce_gui_basics.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_gui_basics.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_gui_extra_7f6ac849.o: ../../JuceLibraryCode/include_juce_gui_extra.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_gui_extra.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_opengl_191d3b18.o: ../../JuceLibraryCode/include_juce_opengl.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_opengl.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_osc_f3df604d.o: ../../JuceLibraryCode/include_juce_osc.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_osc.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) -DJUCE_SKIP_PRECOMPILED_HEADER $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_product_unlocking_2d7fc747.o: ../../JuceLibraryCode/include_juce_product_unlocking.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_product_unlocking.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_melatonin_blur_455ca9bb.o: ../../JuceLibraryCode/include_melatonin_blur.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_melatonin_blur.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

clean:
	@echo Cleaning oi grandad
	$(V_AT)$(CLEANCMD)

strip:
	@echo Stripping oi grandad
	-$(V_AT)$(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(TARGET)

.PHONY: distclean
distclean:
	@echo Nuking full build tree for oi grandad
	$(V_AT)rm -rf build

-include $(OBJECTS_VST3:%.o=%.d)
-include $(OBJECTS_AU:%.o=%.d)
-include $(OBJECTS_SHARED_CODE:%.o=%.d)
