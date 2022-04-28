#!/bin/bash
image="task-env-setup"
docker build -t $image .

# Go to docker container
xhost +SI:localuser:root
docker run  -it \
            --rm \
            -w `pwd` \
            -v `pwd`:`pwd` \
            --privileged=true \
            -e DISPLAY=$DISPLAY \
            --net=host \
            $image \
            bash
