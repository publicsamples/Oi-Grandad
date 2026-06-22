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
  JUCE_OUTDIR := ../../dll

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := 
  endif

  JUCE_PCH     :=
  JUCE_PCH_INC :=

  JUCE_CPPFLAGS := $(DEPFLAGS)  "-DDEBUG=1" "-D_DEBUG=1" "-DJUCER_MACOSX_MAKE_28416E59=1" "-DJUCE_APP_VERSION=1.0.0" "-DJUCE_APP_VERSION_HEX=0x10000" -I../../JuceLibraryCode -I/Users/rick/Documents/GitHub/HISE -I/Users/rick/Documents/GitHub/HISE/JUCE/modules -I/Users/rick/Documents/GitHub/HISE/tools/faust/include $(CPPFLAGS)
  JUCE_CPPFLAGS_DYNAMIC_LIBRARY :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=0" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0"
  JUCE_CFLAGS_DYNAMIC_LIBRARY := -fvisibility=hidden
  JUCE_LDFLAGS_DYNAMIC_LIBRARY := -dynamiclib -install_name @rpath/$(notdir $(JUCE_TARGET_DYNAMIC_LIBRARY))
  JUCE_TARGET_DYNAMIC_LIBRARY := oigrandad_debug.dylib
  JUCE_STRIPCMD_DYNAMIC_LIBRARY := true

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0 -isysroot $(shell xcrun --sdk macosx --show-sdk-path) -mmacosx-version-min=11.0 -Wno-reorder -Wno-inconsistent-missing-override -faligned-allocation -ffp-contract=off $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 -stdlib=libc++ $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -fvisibility=hidden -stdlib=libc++ -mmacosx-version-min=11.0 -Wl,-ld_new -framework Accelerate -framework CoreAudio -framework CoreMIDI -framework QuartzCore -framework AudioToolbox -framework Cocoa -framework Foundation -framework IOKit -framework Carbon $(LDFLAGS)

  OBJECTS_DYNAMIC_LIBRARY := \
    $(JUCE_OBJDIR)/include_hi_tools_01_aabcc84d.o \
    $(JUCE_OBJDIR)/Main_90ebc5c2.o \
    $(JUCE_OBJDIR)/RNBO_66f96772.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_01_6050d6b.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_02_61324ec.o \
    $(JUCE_OBJDIR)/include_hi_tools_02_aacadfce.o \
    $(JUCE_OBJDIR)/include_hi_tools_03_aad8f74f.o \
    $(JUCE_OBJDIR)/include_juce_audio_basics_f3f20619.o \
    $(JUCE_OBJDIR)/include_juce_audio_formats_dfad2b82.o \
    $(JUCE_OBJDIR)/include_juce_core_732cd068.o \
    $(JUCE_OBJDIR)/include_juce_data_structures_a0a8d560.o \
    $(JUCE_OBJDIR)/include_juce_dsp_58374bb4.o \
    $(JUCE_OBJDIR)/include_juce_events_be72526e.o \
    $(JUCE_OBJDIR)/include_juce_graphics_398d297c.o \
    $(JUCE_OBJDIR)/include_juce_gui_basics_17deb37e.o \

  CLEANCMD = rm -rf $(JUCE_OUTDIR) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),CI)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/CI
  JUCE_OUTDIR := ../../dll

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := 
  endif

  JUCE_PCH     :=
  JUCE_PCH_INC :=

  JUCE_CPPFLAGS := $(DEPFLAGS)  "-DNDEBUG=1" "-DJUCER_MACOSX_MAKE_28416E59=1" "-DJUCE_APP_VERSION=1.0.0" "-DJUCE_APP_VERSION_HEX=0x10000" -I../../JuceLibraryCode -I/Users/rick/Documents/GitHub/HISE -I/Users/rick/Documents/GitHub/HISE/JUCE/modules -I/Users/rick/Documents/GitHub/HISE/tools/faust/include $(CPPFLAGS)
  JUCE_CPPFLAGS_DYNAMIC_LIBRARY :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=0" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0"
  JUCE_CFLAGS_DYNAMIC_LIBRARY := -fvisibility=hidden
  JUCE_LDFLAGS_DYNAMIC_LIBRARY := -dynamiclib -install_name @rpath/$(notdir $(JUCE_TARGET_DYNAMIC_LIBRARY))
  JUCE_TARGET_DYNAMIC_LIBRARY := oigrandad_ci.dylib
  JUCE_STRIPCMD_DYNAMIC_LIBRARY := $(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(JUCE_TARGET_DYNAMIC_LIBRARY)

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -O1 -isysroot $(shell xcrun --sdk macosx --show-sdk-path) -mmacosx-version-min=11.0 -Wno-reorder -Wno-inconsistent-missing-override -faligned-allocation -ffp-contract=off $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 -stdlib=libc++ $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -fvisibility=hidden -stdlib=libc++ -mmacosx-version-min=11.0 -Wl,-ld_new -framework Accelerate -framework CoreAudio -framework CoreMIDI -framework QuartzCore -framework AudioToolbox -framework Cocoa -framework Foundation -framework IOKit -framework Carbon $(LDFLAGS)

  OBJECTS_DYNAMIC_LIBRARY := \
    $(JUCE_OBJDIR)/include_hi_tools_01_aabcc84d.o \
    $(JUCE_OBJDIR)/Main_90ebc5c2.o \
    $(JUCE_OBJDIR)/RNBO_66f96772.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_01_6050d6b.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_02_61324ec.o \
    $(JUCE_OBJDIR)/include_hi_tools_02_aacadfce.o \
    $(JUCE_OBJDIR)/include_hi_tools_03_aad8f74f.o \
    $(JUCE_OBJDIR)/include_juce_audio_basics_f3f20619.o \
    $(JUCE_OBJDIR)/include_juce_audio_formats_dfad2b82.o \
    $(JUCE_OBJDIR)/include_juce_core_732cd068.o \
    $(JUCE_OBJDIR)/include_juce_data_structures_a0a8d560.o \
    $(JUCE_OBJDIR)/include_juce_dsp_58374bb4.o \
    $(JUCE_OBJDIR)/include_juce_events_be72526e.o \
    $(JUCE_OBJDIR)/include_juce_graphics_398d297c.o \
    $(JUCE_OBJDIR)/include_juce_gui_basics_17deb37e.o \

  CLEANCMD = rm -rf $(JUCE_OUTDIR) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release
  JUCE_OUTDIR := ../../dll

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := 
  endif

  JUCE_PCH     :=
  JUCE_PCH_INC :=

  JUCE_CPPFLAGS := $(DEPFLAGS)  "-DNDEBUG=1" "-DJUCER_MACOSX_MAKE_28416E59=1" "-DJUCE_APP_VERSION=1.0.0" "-DJUCE_APP_VERSION_HEX=0x10000" -I../../JuceLibraryCode -I/Users/rick/Documents/GitHub/HISE -I/Users/rick/Documents/GitHub/HISE/JUCE/modules -I/Users/rick/Documents/GitHub/HISE/tools/faust/include $(CPPFLAGS)
  JUCE_CPPFLAGS_DYNAMIC_LIBRARY :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=0" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_RTAS=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0"
  JUCE_CFLAGS_DYNAMIC_LIBRARY := -fvisibility=hidden
  JUCE_LDFLAGS_DYNAMIC_LIBRARY := -dynamiclib -install_name @rpath/$(notdir $(JUCE_TARGET_DYNAMIC_LIBRARY))
  JUCE_TARGET_DYNAMIC_LIBRARY := oigrandad.dylib
  JUCE_STRIPCMD_DYNAMIC_LIBRARY := $(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(JUCE_TARGET_DYNAMIC_LIBRARY)

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -O3 -isysroot $(shell xcrun --sdk macosx --show-sdk-path) -mmacosx-version-min=11.0 -Wno-reorder -Wno-inconsistent-missing-override -faligned-allocation -ffp-contract=off $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 -stdlib=libc++ $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -fvisibility=hidden -stdlib=libc++ -mmacosx-version-min=11.0 -Wl,-ld_new -framework Accelerate -framework CoreAudio -framework CoreMIDI -framework QuartzCore -framework AudioToolbox -framework Cocoa -framework Foundation -framework IOKit -framework Carbon $(LDFLAGS)

  OBJECTS_DYNAMIC_LIBRARY := \
    $(JUCE_OBJDIR)/include_hi_tools_01_aabcc84d.o \
    $(JUCE_OBJDIR)/Main_90ebc5c2.o \
    $(JUCE_OBJDIR)/RNBO_66f96772.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_01_6050d6b.o \
    $(JUCE_OBJDIR)/include_hi_dsp_library_02_61324ec.o \
    $(JUCE_OBJDIR)/include_hi_tools_02_aacadfce.o \
    $(JUCE_OBJDIR)/include_hi_tools_03_aad8f74f.o \
    $(JUCE_OBJDIR)/include_juce_audio_basics_f3f20619.o \
    $(JUCE_OBJDIR)/include_juce_audio_formats_dfad2b82.o \
    $(JUCE_OBJDIR)/include_juce_core_732cd068.o \
    $(JUCE_OBJDIR)/include_juce_data_structures_a0a8d560.o \
    $(JUCE_OBJDIR)/include_juce_dsp_58374bb4.o \
    $(JUCE_OBJDIR)/include_juce_events_be72526e.o \
    $(JUCE_OBJDIR)/include_juce_graphics_398d297c.o \
    $(JUCE_OBJDIR)/include_juce_gui_basics_17deb37e.o \

  CLEANCMD = rm -rf $(JUCE_OUTDIR) $(JUCE_OBJDIR)
endif

.PHONY: clean all strip

all : $(JUCE_OUTDIR)/$(JUCE_TARGET_DYNAMIC_LIBRARY)

$(JUCE_OUTDIR)/$(JUCE_TARGET_DYNAMIC_LIBRARY) : $(OBJECTS_DYNAMIC_LIBRARY) $(RESOURCES)
	@echo Linking "oi grandad - Dynamic Library"
	-$(V_AT)mkdir -p $(JUCE_BINDIR)
	-$(V_AT)mkdir -p $(JUCE_LIBDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)
	$(V_AT)$(CXX) -o $(JUCE_OUTDIR)/$(JUCE_TARGET_DYNAMIC_LIBRARY) $(OBJECTS_DYNAMIC_LIBRARY) $(JUCE_LDFLAGS) $(JUCE_LDFLAGS_DYNAMIC_LIBRARY) $(RESOURCES) $(TARGET_ARCH)
	-$(V_AT)$(JUCE_STRIPCMD_DYNAMIC_LIBRARY)

$(JUCE_OBJDIR)/include_hi_tools_01_aabcc84d.o: ../../JuceLibraryCode/include_hi_tools_01.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_tools_01.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Main_90ebc5c2.o: ../../Source/Main.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Main.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RNBO_66f96772.o: ../../Source/RNBO.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling RNBO.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_dsp_library_01_6050d6b.o: ../../JuceLibraryCode/include_hi_dsp_library_01.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_dsp_library_01.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_dsp_library_02_61324ec.o: ../../JuceLibraryCode/include_hi_dsp_library_02.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_dsp_library_02.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_tools_02_aacadfce.o: ../../JuceLibraryCode/include_hi_tools_02.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_tools_02.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_hi_tools_03_aad8f74f.o: ../../JuceLibraryCode/include_hi_tools_03.cpp $(JUCE_PCH)
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_hi_tools_03.cpp"
	$(V_AT)$(CXX) $(JUCE_PCH_INC) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_basics_f3f20619.o: ../../JuceLibraryCode/include_juce_audio_basics.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_basics.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_formats_dfad2b82.o: ../../JuceLibraryCode/include_juce_audio_formats.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_formats.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_core_732cd068.o: ../../JuceLibraryCode/include_juce_core.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_core.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_data_structures_a0a8d560.o: ../../JuceLibraryCode/include_juce_data_structures.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_data_structures.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_dsp_58374bb4.o: ../../JuceLibraryCode/include_juce_dsp.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_dsp.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_events_be72526e.o: ../../JuceLibraryCode/include_juce_events.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_events.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_graphics_398d297c.o: ../../JuceLibraryCode/include_juce_graphics.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_graphics.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_gui_basics_17deb37e.o: ../../JuceLibraryCode/include_juce_gui_basics.mm
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_gui_basics.mm"
	$(V_AT)$(CXX) -x objective-c++ $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_DYNAMIC_LIBRARY) $(JUCE_CFLAGS_DYNAMIC_LIBRARY) -o "$@" -c "$<"

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

-include $(OBJECTS_DYNAMIC_LIBRARY:%.o=%.d)
