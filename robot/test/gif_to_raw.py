
import os,sys
#import struct
import array
from PIL import Image
#import Image


def pack16bitRGB(pixel):
#    print(pixel)
    try:
        r,g,b,a = pixel
    except (ValueError,TypeError):
        try:
            a = 0
            r,g,b = pixel
        except (ValueError,TypeError):
            r = g = b = pixel
    #    print(r,g,b,a,"\n")
    word = ( (int(r>>3)<<11) |
             (int(g>>2)<< 5) |
             (int(b>>3)<< 0) )
    return word
    # return ((word>>8)&0xFF) | ((word&0xFF)<<8)


def convert_to_raw(img):
    print(SCREEN_WIDTH)
    print(SCREEN_HEIGHT)
    bitmap = [0x0000]*(SCREEN_WIDTH*SCREEN_HEIGHT)
    for y in range(img.size[1]):
        for x in range(img.size[0]):
            pixel = pack16bitRGB(img.getpixel((x,y)))
            bitmap[(y)*SCREEN_WIDTH + (x)] = pixel
    return bitmap


RAW = 1

def convert_frame_to_data(frame):
    newframe = frame.convert('RGBA')
    newframe = convert_to_raw(newframe)
    data = array.array("H",newframe)
    return data

def extractGifFrames(inGif):
    frame = Image.open(inGif)
    nframes = 0
    with open('%s.raw' % (os.path.basename(inGif),), "wb+") as f:
        while frame:
            data = convert_frame_to_data(frame)
            f.write(data.tostring())
            nframes += 1
            try:
                frame.seek( nframes )
            except EOFError:
                break;
    return True

def convertImages(dirname, images):
    outfilename = '%s/anim.raw' % dirname
    with open(outfilename, "wb+") as f:
        nframes = 0
        for filename in images:
            frame = Image.open(filename)
            data = convert_frame_to_data(frame)
            f.write(data.tostring())
            nframes += 1

        print('wrote {} frames to {}'.format(nframes, outfilename))
            
if len(sys.argv) != 4:
    print('Usage: gif_to_raw.py image.gif WIDTH HEIGHT')
    print('Legacy vector is 184x96 new is 160x80')
    exit(-1)
else:
    SCREEN_WIDTH = int(sys.argv[2])
    SCREEN_HEIGHT = int(sys.argv[3])

    extractGifFrames(sys.argv[1])
