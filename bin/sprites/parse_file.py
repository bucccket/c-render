from xml.etree import ElementInclude


file = open("bin/sprites/animtest_conc.txt", "r")
text = file.read()

split_text = text.split("\"")
res = b""
for element in split_text:
    if element != '\n' and element != '':
        res += (0x1681).to_bytes(4, "little")  # size of section
        res += b"g_Anim1_F1\0"  # name
        res += (0x00).to_bytes(2, "little")  # x
        res += (0x00).to_bytes(2, "little")  # y
        res += (70).to_bytes(2, "little")  # width
        res += (41).to_bytes(2, "little")  # height
        element = element.replace("\n", "")
        print("\""+str(element)+"\"")
        element = element.encode("ascii")
        res += element + b"\0"  # data
        res += b" " * (41*70) + b"\0"  # mask

resultfile = open("bin/sprites/res.graphic", "wb")
resultfile.write(res)
resultfile.close()

print("done.")
