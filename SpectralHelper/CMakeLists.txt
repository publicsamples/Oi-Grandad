cmake_minimum_required(VERSION 3.22)

project(SpectralHelper VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JUCE_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/../HISE/JUCE")
set(JUCE_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/JUCE")

include(../HISE/JUCE/extras/Build/CMake/JUCEUtils.cmake)
add_subdirectory(../HISE/JUCE/extras/Build JUCE_build_tools)
add_subdirectory(../HISE/JUCE/modules JUCE_modules)

juce_add_gui_app(SpectralHelper
    PRODUCT_NAME "SpectralHelper")

target_sources(SpectralHelper
    PRIVATE
        Source/Main.cpp
        Source/MainComponent.cpp
        Source/WaveformPanel.cpp
        Source/AnalysisEngine.cpp
        Source/SpectralAssetWriter.cpp)

target_include_directories(SpectralHelper
    PRIVATE
        Source)

target_compile_definitions(SpectralHelper
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0)

target_link_libraries(SpectralHelper
    PRIVATE
        juce::juce_gui_extra
        juce::juce_audio_utils
        juce::juce_dsp
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags)
