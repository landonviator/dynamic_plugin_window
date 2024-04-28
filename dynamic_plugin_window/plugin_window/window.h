#pragma once
#ifndef PluginWindow_h
#define PluginWindow_h
#include <juce_gui_basics/juce_gui_basics.h>

namespace viator {
    class DynamicPluginWindow
    {
    public:

        /**
         * @brief Configures the window size of the plugin according to the user's screen dimensions.
         *
         * @author Landon Viator
         * @param editor Reference to the plugin's editor for accessing static methods.
         * @param aspect_ratio Aspect ratio to determine the width relative to the height.
         */
        static inline void setPluginWindowSize (
            juce::AudioProcessorEditor& editor,
            const double aspect_ratio)
        {
            // Grab the window instance and create a rectangle
            const juce::Rectangle<float> screen_bounds_logical =
                juce::Desktop::getInstance()
                .getDisplays()
                .getPrimaryDisplay()
                ->totalArea.toFloat();

            const auto height = screen_bounds_logical.getHeight()
                * calculateMultiplier(screen_bounds_logical.getHeight());
            const auto width = static_cast<float>(height * aspect_ratio);

            editor.setResizable (true, true);
            editor.getConstrainer()->setFixedAspectRatio(aspect_ratio);
            editor.setResizeLimits (
                static_cast<int>(width * 0.5),
                static_cast<int>(height * 0.5),
                static_cast<int>(width * 1.5),
                static_cast<int>(height * 1.5));

            editor.setSize (static_cast<int>(width), static_cast<int>(height));
        }

    private:

        static float calculateMultiplier(float screenHeight)
        {
            // Define the upper and lower bounds of the
            // screen heights and corresponding multipliers
            constexpr float min_height = 700.0f;
            constexpr const float max_height = 3840.0f;
            constexpr const float min_multiplier = 0.6f;
            constexpr const float max_multiplier = 0.15f;

            // Clamp the screen height to be within bounds
            screenHeight = std::max(min_height, std::min(screenHeight, max_height));

            // Calculate the multiplier based on a linear interpolation between min and max
            return min_multiplier
                + (max_multiplier - min_multiplier)
                * (screenHeight - min_height)
                / (max_height - min_height);
        }
    };
}

#endif
