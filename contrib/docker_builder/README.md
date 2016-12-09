# Dockerfile for building ecocoin binaries.

Now, you can build your own ecocoin files on all systems with docker and do it easy without installing depends on your system.

## How:

### Build docker image

```
sudo docker build .
```

### Run docker container

Builder will return HASH of image
Example:
Successfully built 9bbff825d50f

```
sudo docker run -it -v ~/path/to/ecocoin/folder:/ecocoin 9bbff825d50f
```

If your system uses SELINUX you may use --privileged=true key

```
sudo docker run --privileged=true -it -v ~/development/ecocoin:/ecocoin 9bbff825d50f
```

See ecocoin-qt file in used ecocoin folder and ecocoind file in src subfolder.