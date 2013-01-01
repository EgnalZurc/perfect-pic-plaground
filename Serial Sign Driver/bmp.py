import Image

rows = []
#The rows on the marquee blocks are jumbled, and this is the mapping
roworder = [6, 7, 5, 1, 4, 2, 3, 0]

#Convert array to binary number, LSB first
def arrayToBinary(array):
    arraybinary = 0
    position = 1
    for elem in array:
        arraybinary = arraybinary + elem*position
        position = position*2
    return arraybinary

#Create binary number for individual rows
def processRows(imag_rows):
    rows = []
    for imag_row in imag_rows:
        new_imag_row = [ imag_row[i] for i in roworder ]
        #print imag_row, "->", new_imag_row
        rowbinary = arrayToBinary(new_imag_row)
        #print rowbinary
        rows.append(rowbinary)
    return rows

#Create binary number for sections of individual rows
def processRowsPart(imag_rows,widthSection,index):
    rows = []
    for imag_row in imag_rows:
        imag_row = imag_row[widthSection*index:widthSection*(index+1)]
        new_imag_row = [ imag_row[i] for i in roworder ]
        #print imag_row, "->", new_imag_row
        rowbinary = arrayToBinary(new_imag_row)
        #print rowbinary
        rows.append(rowbinary)
    return rows

#Rotates each row in the collection of rows
def rotateEachRowOnce(imag_rows):
    new_imag_rows = []
    for imag_row in imag_rows:
        new_imag_row = imag_row[1:] + imag_row[:1]
        new_imag_rows.append(new_imag_row)
    return new_imag_rows

#Takes the long list of the image pixels and splits it into individual rows
def splitToRows(imag,width):
    imag_rows = []
    while imag:
        imag_row = imag[:width]
        imag_rows.append(imag_row)
        imag = imag[width:]
    return imag_rows

#Split section of BMP file into pixel rows and process into binary
def makePicturePart(path,widthTotal,widthSection,sectionIndex):
    im = Image.open(path)
    imag = list(im.getdata())
    imag_rows = splitToRows(imag,widthTotal)
    return processRowsPart(imag_rows,widthSection,sectionIndex)

#Split BMP file into pixel rows and process into binary
def makePicture(path,width):
    im = Image.open(path)
    imag = list(im.getdata())
    imag_rows = splitToRows(imag,width)
    return processRows(imag_rows)

#Take large BMP and partition it into image blocks for multi-block marquees
def makeAllPics(path, widthTotal, sections):
    widthSection = widthTotal/sections
    sectionList = []
    for i in range(0,sections):
        sectionList.append(makePicturePart(path,widthTotal,widthSection,sections-1-i))
    return sectionList

def makeAnimation(pathList, widthTotal, sections):
    frames = []
    for path in pathList:
        frames.append(makeAllPics(path, widthTotal, sections))
    return frames

makePicture("C:\\Users\\Public\\Arial_Letters2\H.bmp",8)
makePicture("C:\\Users\\Public\\Arial_Letters2\A.bmp",8)
makePicture("C:\\Users\\Public\\Arial_Letters2\P.bmp",8)
makePicture("C:\\Users\\Public\\Arial_Letters2\P.bmp",8)
makePicture("C:\\Users\\Public\\Arial_Letters2\Y.bmp",8)
print
makePicture("C:\\Users\\Public\\Arial_Letters2\N.bmp",8)
makePicture("C:\\Users\\Public\\Arial_Letters2\E.bmp",8)
makePicture("C:\\Users\\Public\\Arial_Letters2\W.bmp",8)
print
makePicture("C:\\Users\\Public\\Arial_Letters2\Y.bmp",8)
makePicture("C:\\Users\\Public\\Arial_Letters2\E.bmp",8)
makePicture("C:\\Users\\Public\\Arial_Letters2\A.bmp",8)
makePicture("C:\\Users\\Public\\Arial_Letters2\R.bmp",8)
print
makePicture("C:\\Users\\Public\\Penis\\penis5.bmp",8)
makePicture("C:\\Users\\Public\\Penis\\penis4.bmp",8)
makePicture("C:\\Users\\Public\\Penis\\penis3.bmp",8)
makePicture("C:\\Users\\Public\\Penis\\penis2.bmp",8)
makePicture("C:\\Users\\Public\\Penis\\penis1.bmp",8)
print
print makeAllPics("C:\\Users\\Public\\Penis\\penis_1.bmp", 40, 5)
print
print makeAllPics("C:\\Users\\Public\\Penis\\penis_2.bmp", 40, 5)
print
print makeAllPics("C:\\Users\\Public\\Penis\\penis_3.bmp", 40, 5)
print
print makeAllPics("C:\\Users\\Public\\Penis\\penis_4.bmp", 40, 5)
print
print makeAllPics("C:\\Users\\Public\\Penis\\penis_5.bmp", 40, 5)
print
print makeAllPics("C:\\Users\\Public\\Penis\\penis_6.bmp", 40, 5)
print
print makeAllPics("C:\\Users\\Public\\Penis\\penis_7.bmp", 40, 5)
penisPathList = [
    "C:\\Users\\Public\\Penis\\penis_1.bmp",
    "C:\\Users\\Public\\Penis\\penis_2.bmp",
    "C:\\Users\\Public\\Penis\\penis_3.bmp",
    "C:\\Users\\Public\\Penis\\penis_4.bmp",
    "C:\\Users\\Public\\Penis\\penis_5.bmp",
    "C:\\Users\\Public\\Penis\\penis_6.bmp",
    "C:\\Users\\Public\\Penis\\penis_7.bmp"
]
print makeAnimation(penisPathList, 40, 5)
