# DynamicPluginWindow

`DynamicPluginWindow` is a JUCE module designed to dynamically resize audio plugin windows according to the user's screen dimensions. This module ensures that your plugin's user interface is optimally scaled for better usability across different devices and resolutions.

## Author
- Landon Viator

## Features
- **Dynamic Resizing**: Automatically adjusts the plugin window size based on the current screen resolution.
- **Aspect Ratio Maintenance**: Maintains the specified aspect ratio regardless of screen size.
- **Resizable Constraints**: Allows the plugin window to be resizable within specified limits, ensuring that the UI remains functional and visually appealing at various sizes.

## Requirements
- JUCE 6 or later

## Installation
To integrate `DynamicPluginWindow` into your JUCE-based audio plugin project:

1. Clone this repository or download the files into your project directory.
2. Include the repo as a Juce submodule in the Projucer under **_Modules -> add module from a specificed folder_** or if you're using CMake, **_add juce_add_module()_** to your CMakeLists.txt file, passing in the file path of the module.

## Usage
To use `DynamicPluginWindow` in your plugin:

1. Include the `DynamicPluginWindow` class in your plugin editor (only if you're doing a header-only approach instead of bringing in as a Juce submodule).
2. Call `DynamicPluginWindow::setPluginWindowSize` from your editor's constructor or whenever you need to resize the plugin window. This replaces the **_setSize()_** call that in in the constructor by default. For example:

   ```cpp
   #include "DynamicPluginWindow.h"

   MyPluginEditor::MyPluginEditor()
   {
       double aspect_ratio = 16.0 / 9.0; // Desired aspect ratio
       viator::DynamicPluginWindow::setPluginWindowSize(*this, aspect_ratio);
   }
   ```

## Support

If you like my work and would like to support me creating more audio applications, check out my [Patreon](https://www.patreon.com/ViatorDSP) where you can donate and download all of my current plugins! I also have a [GumRoad](https://viatordsp.gumroad.com/?_gl=1*18tqfoy*_ga*MTg2MjcxNDgyNS4xNjg5OTI3NDE3*_ga_6LJN6D94N6*MTY5MjM5NjQ1Ni4xODguMS4xNjkyMzk2NTExLjAuMC4w) store with my most recent plugins.
