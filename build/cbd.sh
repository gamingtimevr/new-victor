#!/bin/bash

set -e

echo "Cleaning..."
./build/clean.sh

echo "Building..."
./build/build-v.sh

echo "Deploying..."
./build/deploy-v.sh
