# STag: A Stable Fiducial Marker System

Code used in the following paper:

[B. Benligiray; C. Topal; C. Akinlar, "STag: A Stable Fiducial Marker System," Image and Vision Computing (Accepted), 2019.](https://arxiv.org/abs/1707.06292)

Markers (will provide a generation script in the future):

https://drive.google.com/drive/folders/0ByNTNYCAhWbIV1RqdU9vRnd2Vnc

### TODO:
* Add a makefile
* Write Matlab and Python wrappers

[![Supplementary Video](https://user-images.githubusercontent.com/19530665/57184379-6a250580-6ec3-11e9-8ab3-7e139966f13b.png)](https://www.youtube.com/watch?v=vnHI3GzLVrY) 

Some figures from the paper:

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179654-c0c11e00-6e88-11e9-9ca5-0c0153b28c91.png"/>
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179660-cae31c80-6e88-11e9-8f80-bf8e24e59957.png"/>
</p>

## Dockerfile and example code:

Set BUILD_TESTING in CMakeLists to ON, and build the Dockerfile

### Dockerfile

``` Dockerfile
# syntax=docker/dockerfile:1

# Use an official Ubuntu runtime as the base image
FROM ubuntu:22.04

# Update the system
RUN apt-get update -y && apt-get upgrade -y

# Install OpenCV
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libopencv-dev cmake g++
# RUN apt-get install -y g++

# Copy the current directory contents into the container at /app
COPY . /app

# Set the working directory to /app
WORKDIR /app

# Create a build directory and navigate into it
RUN mkdir build && cd build

# Run CMake to generate the Makefile
RUN cmake .

# Build the project
RUN make

# Run the compiled binary
CMD ["./stag_main"]
```
