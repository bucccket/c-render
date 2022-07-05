file = open("dump.txt", "r")
text = file.read()

#frames ? 286

width = 40
height = 24

split_text = text.split("\"")
res = b""
for element in split_text:
    if element != '\n' and element != '':
        res += (0x0882).to_bytes(4, "little")  # size of section
        res += b"g_Anim8\0"  # name
        res += (0x00).to_bytes(2, "little")  # x
        res += (0x00).to_bytes(2, "little")  # y
        res += (width).to_bytes(2, "little")  # width
        res += (height).to_bytes(2, "little")  # height
        element = element.replace("\n", "")
        print("\""+str(element)+"\"")
        element = element.encode("ascii")
        res += element + b"\0"  # data
        res += b" " * (width*height) + b"\0"  # mask

resultfile = open("res.graphic", "wb")
resultfile.write(res)
resultfile.close()

print("done.")
