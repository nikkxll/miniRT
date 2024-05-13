# Camera's position and direction 03
R 1000 800
# Ambient Light
# <intensity: 0-1> <color: red, green, blue>
A                      0.3        255,255,255

# Camera
# <coordinates of camera position: x,y,z> <camera view: x,y,z> <pov:x,y,z>
C   0,0,0         0,0,1   90

# Light
# <coordinates: x,y,z> <brightness: 0-1> <color:red,green,blue>
l   0,10,0            0.5         	255,255,255
#l   10,10,0               0.3           255,255,255
#l  0,10,-10              0.5         255,255,255

# Sphere
# <coordinates: x,y,z> <diameter> <color:red,green,blue>
#sp  -1,2,4               0.1           255,255,0
#sp  1.2,0,6               2           255,0,0
#sp  0,0,0              2           255,0,0
#sp  0.2,1.7,3.7        1           0,0,255
#sp  -3,0.5,5           1           255,255,0
sp  3,2,5             2           0,255,0 checker 0,0,250 10
sp  3,-2,5             2           0,255,0 

# Plane 
# <coordinates: x,y,z> <origin:x,y,z> <color:red,green,blue>
pl  0,-2,10            0,1,0              0,0,250  checker 250,0,0 1
#pl  0,10,0            0,1,0              0,250,0
pl  0,0,10            0,0,-1              250,0,0

# Cylinder
# <coordinates: x,y,z>  <orientation: x,y,z> <diameter: >= 0> <height: >= 0> <color:red,green,blue>
cy  0,0,5       1,1,1          1      4      255,255,255 checker 255,0,0 10
cy  0,0,5       0,1,0          1      4      0,255,0 checker 0,0,0 10
cy  0,0,5       1,0,0          1      4      255,0,0 checker 0,0,0 10
cy  0,0,5       0,0,1          1      4      255,255,255 checker 0,0,0 10
cy  -3,0,5       0,0,1          1      4      255,255,255
#cy  0,0,5       0,1,0.4         1      2      0,100,255

# Cylinder
# <coordinates: x,y,z>  <orientation: x,y,z> <diameter: >= 0> <height: >= 0> <color:red,green,blue>
co  -3,2,5       1,1,1          1      4      255,255,255 checker 255,0,0 10
co  -3,2,5       0,1,0          1      4      0,255,0 checker 0,0,0 10
co  -3,2,5       1,0,0          1      4      255,0,0 checker 0,0,0 10
co  -3,2,5       0,0,1          1      4      255,255,255 checker 0,0,0 10
#co  -3,2,5       0,0,1          1      4      255,255,255