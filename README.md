# MagiX

## Getting started

This project aims to make a game inspired by board games such as Mystic Vale.

## Build instructions

### Environment

We use Ubuntu, but it also works on most Linux distributions.
Following instructions will install build dependencies on Debian.

```
sudo apt install git dia ghostscript cmake g++ lcov gcovr libxml2-dev libsfml-dev libboost-test-dev
git clone https://github.com/sonibla/plt.git
```

### Build binaries

```
mkdir build
cd build
cmake ..
make all
```

Binaries are generated in *bin/* folder

You can also display a list of makefile targets with :
```
make help
```

### Features
Please make sure that you are in the top level folder of the project before trying to execute binaries.

You can test the rendering :
```
bin/client render
```

You can test the state evolution :

each player will pick the first card of the first river when you press the spacebar.
```
bin/client engine
```

You can test the random ai :

each player will be an ai that pick a decision at random among possible decisions.
```
bin/client random_ai
```

You can test the replay :

At the end of a game such as a game played by ai, a replay of the game is stored in the replays folder.

You can simply replay the game that has been played.
```
bin/client replay *replayfile*
```


## Authors

* [**Maxime Marroufin**](https://github.com/Marroufin)
* [**Quentin Chhean**](https://github.com/quenchhe)
* [**Abinaya Mathibala**](https://github.com/AbinayaM-coder)
* [**Alban Benmouffek**](https://github.com/sonibla)

See also the list of [contributors](https://github.com/sonibla/plt/contributors) who participated in this project.
