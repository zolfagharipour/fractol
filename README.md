# Fractol

Fractol is a graphical project aimed at exploring fractals, complex mathematical sets that exhibit a repeating pattern displayed at every scale. This project uses the MiniLibX graphics library, providing a simple interface to the display hardware to render fractals. It allows users to explore different types of fractals, such as Mandelbrot, Julia, and Newton sets, with interactive controls to zoom and alter their appearance dynamically.

## Warning for 42 Students

This repository is intended as a reference and educational tool. **42 students are strongly advised not to copy this code without fully understanding its functionality.** Plagiarism in any form is against 42's principles and could lead to serious academic consequences. Use this repository responsibly to learn and better understand how to implement similar functionalities on your own.

## Features

- **Fractal Rendering**: Supports rendering of the Mandelbrot set, Julia set, and Newton fractal.
- **Dynamic Interaction**: Users can zoom in and out on the fractals using the mouse wheel, with the zoom centering on the mouse position.
- **Adjustable Parameters**: Different parameters for the Julia set can be passed on the command line to alter its appearance.
- **Color Shifting**: Color ranges shift dynamically, enhancing the visual experience with psychedelic effects.
- **Smooth Graphics Management**: Window management is smooth and responsive. Minimizing or switching windows does not interrupt the experience.
- **Control via Keyboard and Mouse**: In addition to zooming, the view can be moved using arrow keys.

## Setup

The MiniLibX library is included in the repository. Follow these instructions to compile and run the project:

```
git clone https://github.com/yourusername/fractol.git
cd fractol
make
```

## Usage

To run the program, use one of the following commands depending on the fractal you want to view:

```
./fractol mandelbrot
./fractol julia
./fractol newton
```

If no valid parameter is provided, the program will display a list of valid fractal names and then exit.

## Controls

- **Zoom**: Mouse wheel up to zoom in, wheel down to zoom out.
- **Move**: Arrow keys to move the view.
- **Exit**: Press ESC or click the window's close button to exit the program.

## Additional Features

The project includes the following bonus features:

- **Additional Fractal**: The Newton fractal is implemented as an additional set to explore.
- **Mouse-Centered Zoom**: Zooming in and out follows the actual mouse position, enhancing the exploration experience.
- **Color Shift**: The color range shifts dynamically to create varying visual effects. you can also change the color theme by pressing C in keyboard.

