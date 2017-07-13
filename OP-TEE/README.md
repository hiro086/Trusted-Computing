# Ubuntu 14.04 64位 搭建OP-TEE环境

## 安装repo

```c
mkdir ~/bin

PATH=~/bin:$PATH
//下载
curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo

chmod a+x ~/bin/repo
```

### 一些情况下会报如下错误
```c
  fatal: Cannot get https://gerrit.googlesource.com/git-repo/clone.bundle
  fatal: error [Errno 101] Network is unreachable
```
#### 此处是由于下载老版本repo的原因，文件里有我运行成功的一个版本源码，复制替换repo文件即可，注意已替换googlesource的URL到国内镜像站


## 安装依赖库
```c
sudo apt-get install android-tools-fastboot autoconf bison cscope curl \
flex gdisk libc6:i386 libfdt-dev libglib2.0-dev \
libpixman-1-dev libstdc++6:i386 libz1:i386 netcat \
python-crypto python-serial uuid-dev xz-utils zlib1g-dev
```
## 下载OP-TEE源码
```c
mkdir -p $HOME/devel/optee

cd $HOME/devel/optee

repo init -u https://github.com/OP-TEE/manifest.git -m default_stable.xml -b master
```
## 编译
```c
cd build

make -f toolchain.mk toolchains

make -f qemu.mk all

make -f qemu.mk run-only

```
### 遇到如下错误

ImportError: No module named wand.image make[1]: *** [out/arm/ta_arm32-libbutee/tui/default_bold.c] Error 1

解决方法：apt-get install libmagickwand-dev and python-wand

(qemu) qemu-system-arm: cannot set up guest memory 'xxx.ram': Cannot a

解决方法：增加虚拟机内存


