import os
import io
import zlib

filename = "animtest_3.cpr"

# general
header = None
inflate = None
deflate = None
compression = False

# sprite header
formatVersion = None
spriteName = " "
frameCount = None
translateX = None
translateY = None

data = None


def parseSpriteHeader(f):
    formatVersion = f.read(2)
    char = f.read(1)
    while(char != b'\x00'):
        spriteName = spriteName + char
        char = f.read(1)


def readFileHeader(f):
    if os.path.splitext(filename)[1] == ".cpr":
        header = f.read(4)
        inflate = f.read(4)
        deflate = f.read(4)
        f = io.BytesIO(zlib.decompress(f.read()))
        compression = True
    else:
        header = f.read(4)


if __name__ == "__main__":
    print("launched "+__name__+" module .")

    f = open("sprites/"+filename, "rb")
    readFileHeader(f)
    parseSpriteHeader(f)

    print("done.")
