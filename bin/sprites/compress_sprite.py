from fileinput import close
import zlib

target = "animtest_5.spr"

dInflated = open(target,"rb").read()
szInflate = len(dInflated)
dDeflated = zlib.compress(dInflated[4:],zlib.Z_BEST_COMPRESSION) #remove header before compression
szDeflated = len(dDeflated)

out = b""
out += (0xDEADBEEF).to_bytes(4, "little")
out += szInflate.to_bytes(4, "little")
out += szDeflated.to_bytes(4, "little")
out += dDeflated

open(target[:-3]+"cpr","wb").write(out)
print("done")