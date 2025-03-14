Physics Engine with Button Toggle
Overview
This project is a basic physics engine simulation using SFML (Simple and Fast Multimedia Library). The engine simulates gravity on a red rectangle, and you can interact with it by toggling the floor’s state (solid or non-solid) using a button in the top right corner of the window.

Features
Gravity Simulation: The rectangle falls under the influence of gravity.
Toggle Floor: A button allows toggling the floor between solid (blue) and non-solid (green).
Button with Cooldown: The button has a cooldown mechanism to prevent multiple clicks in quick succession.
Requirements
Before running the project, you must have the following installed:

SFML Library: Download and install SFML from SFML Downloads.
C++ Compiler: Ensure you have a C++ compiler, such as GCC or Visual Studio.
CMake (Optional, for building): You can use CMake to configure and build the project.
Setup Instructions
Clone the repository:

bash
Copy
Edit
git clone https://github.com/yourusername/physics-engine-with-button-toggle.git
Install SFML: Follow the instructions for installing SFML for your platform from the SFML website.

Compile the Project: If you're using CMake, you can create a build folder and compile the project as follows:

bash
Copy
Edit
mkdir build
cd build
cmake ..
make
Alternatively, you can manually compile the files using your preferred C++ build tool or IDE.

Run the Application: After building the project, you can run the executable (e.g., ./PhysicsEngine on Linux/Mac or PhysicsEngine.exe on Windows) to start the simulation.

Controls
Click on the button in the top-right corner of the window to toggle the floor between solid (blue) and non-solid (green).
Gravity: The red rectangle will be affected by gravity and will fall until it collides with the floor.
Project Structure
bash
Copy
Edit
/PhysicsEngine
├── /assets
│   └── Halo Dek.ttf  # Font for the button (can be removed for the no-text version)
├── /src
│   ├── main.cpp      # Main file with the simulation and button logic
│   ├── Button.cpp    # Button class implementation
│   └── Button.h      # Button class header
└── CMakeLists.txt    # CMake build configuration (optional)
License
This project is licensed under the MIT License - see the LICENSE file for details.

Credits
SFML: The project uses the SFML library for graphics and window management. Visit SFML for more information.
Halo Dek.ttf: Font used for the button
