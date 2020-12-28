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
make -j
```

Binaries are generated in *bin/* folder

You can also display a list of makefile targets with :
```
make help
```

## Authors

* [**Maxime Marroufin**](https://github.com/Marroufin)
* [**Quentin Chhean**](https://github.com/quenchhe)
* [**Abinaya Mathibala**](https://github.com/AbinayaM-coder)
* [**Alban Benmouffek**](https://github.com/sonibla)

See also the list of [contributors](https://github.com/sonibla/plt/contributors) who participated in this project.
