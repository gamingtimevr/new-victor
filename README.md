# new-victor

Welcome to `new-victor`. This is the home of the Anki Vector robot's source code, with no LFS. Original README: [README-orig.md](/README-orig.md)

Check the [wiki](https://github.com/kercre123/victor/wiki) for more information about the leak, what we can do with this, and general Vector info.

## Changes

- This repository is a modified version of [wireOS,](github.com/os-vector/wire-os-victor) made by Wire (kercre123). RainbOS is baisicaly just a bunch of changes I personaly wanted, plus some cool rainbow and colorful animations. This is my way of learning how to use Git and code.

## Building (Linux)

 - Prereqs: Make sure you have `docker` and `git-lfs` installed.

1. Clone the repo and cd into it:

```
cd ~
git clone --recurse-submodules -b RainbOS https://github.com/gamingtimevr/new-victor
cd new-victor
```

2. Make sure you can run Docker as a normal user. This will probably involve:

```
sudo groupadd docker
sudo gpasswd -a $USER docker
newgrp docker
sudo chown root:docker /var/run/docker.sock
sudo chmod 660 /var/run/docker.sock
```

3. Run the build script:
```
cd ~/wire-os-victor
./build/build-v.sh
```

3. It should just work! The output will be in `./_build/vicos/Release/`

## Building (ARM64 macOS)

# only works on M1-M4 Macs at the moment, not Intel

 - Prereqs: Make sure you have [brew](https://brew.sh/) installed.
   -  Then: `brew install pyenv git-lfs ccache wget`

1. Clone the repo and cd into it:

```
cd ~
git clone --recurse-submodules -b RainbOS https://github.com/gamingtimevr/new-victor
cd victor
git lfs install
git lfs pull
```

2. Set up Python 2:

```
pyenv install 2.7.18
pyenv init
```

- Add the following to both ~/.zshrc and ~/.zprofile. After doing so, run the commands in your terminal session:
```
export PYENV_ROOT="$HOME/.pyenv"
[[ -d $PYENV_ROOT/bin ]] && export PATH="$PYENV_ROOT/bin:$PATH"
eval "$(pyenv init -)"
pyenv shell 2.7.18
```

3. Disable security:

```
sudo spctl --master-disable
sudo spctl --global-disable
```
- You will have to head to `System Settings -> Security & Privacy -> Allow applications from` and select "Anywhere".


4. Run the build script:
```
cd ~/wire-os-victor
./build/build-v.sh
```

5. It should just work! The output will be in `./_build/vicos/Release/`

## Deploying

1. Echo your robot's IP address to robot_ip.txt (in the root of the victor repo):

```
echo 192.168.1.18 > robot_ip.txt
```

2. Copy your bot's SSH key to a file called `robot_sshkey` in the root of this repo.

3. Run:

```
./build/deploy-v.sh
```
## Tips & Tricks

Cleaning is often important after building new-victor multiple times. It cleans cashed files so that you can make sure you are fully building the repository from scratch. Sometimes, changes may not show up. When that happens, this script comes to the rescue.
To run the Clean script, run:

```
cd new-victor
./build/clean.sh
```

To run the Clean, Build, Deploy script, run:

```
cd new-victor
./build/cbd.sh
```
