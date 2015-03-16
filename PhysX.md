# Introduction #

PhysX setup for Visual studios


# Setup #

There are several steps to get PhysX to run properly

Step 1: MORE INCLUDES

Under the project Properties be sure to include the following folders

lib/PhysicsSDKs/Foundation/include <br>
lib/PhysicsSDKs/Physics/include<br>
lib/PhysicsSDKs/PhysicsLoader/include<br>


Step 2: MORE DEPENDENCIES<br>
<br>
Append the following to the additional dependencies on the project<br>
<br>
PhysXLoader.lib<br>
PhysXCore.lib<br>

Step 3: NEW LIBRARY DIRECTORIES<br>
<br>
Under  Linker -> General there is a cell for Additional Library Directories, the following need to be added<br>
<br>
lib/PhysicsSDKs/lib/Win32<br>

Step 4: A PREPROCESSER DEFINE<br>
<br>
Under c/c++ -> Preprocessor in the cell Prepocessor Defenitions include a WIN32 define<br>
<br>
WIN32<br>
<br>
Step 5: RUN FILES<br>
<br>
If the program is not working at this point you need to copy a few dll files to the Debug folder where the exe is being placed, you need to copy the following<br>
<br>
lib/win32/PhysXCore.dll<br>
lib/win32/PhysXLoader.dll<br>
lib/win32/PhysXDevice.dll<br>
lib/win32/cudart32_30_9.dll<br>

<h1>Tutorial</h1>

<a href='http://www.docstoc.com/docs/25617882/Ageia-PhysX---Tutorials'>http://www.docstoc.com/docs/25617882/Ageia-PhysX---Tutorials</a>