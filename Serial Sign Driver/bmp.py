import Image

rows = []
#The rows on the marquee blocks are jumbled, and this is the mapping
#roworder = [0, 3, 2, 4, 1, 5, 7, 6]
#roworder = [5, 0, 1, 4, 7, 6, 3, 2]
roworder = [1, 2, 7, 6, 3, 0, 5, 4]

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
def scrollEachRowOnce(imag_rows):
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

def getPictureRows(path, width):
    im = Image.open(path)
    imag = list(im.getdata())
    imag_rows = splitToRows(imag,width)
    return imag_rows

def splitToCols(imag, height):
    imag_cols = []
    while imag:
        imag_col = imag[:height]
        imag_cols.append(imag_col)
        imag = imag[height:]
    return imag_cols

def getPictureCols(path, height):
    im = Image.open(path)
    im = im.transpose(Image.FLIP_LEFT_RIGHT).transpose(Image.ROTATE_90)
    imag = list(im.getdata())
    imag_cols = splitToCols(imag,height)
    return imag_cols

def makeRealPicture(path, height):
    return processRows(getPictureCols(path, height))

def processColsPart(imag_cols, height, i):
    cols = []
    imag_cols = imag_cols[height*(i):height*(i+1)]
    for imag_col in imag_cols:
        new_imag_col = [ imag_col[i] for i in roworder ]
        #print imag_row, "->", new_imag_row
        colbinary = arrayToBinary(new_imag_col)
        #print rowbinary
        cols.append(colbinary)
    return cols

print "HIP"
print getPictureCols("C:\\Users\\Public\\Penis\\penis_1.bmp", 8)

def makeFrame(path, height, widthTotal, widthSection):
    allCols = []
    for i in range(0,widthTotal/widthSection):
        allCols.append(processColsPart(getPictureCols(path, height),  height, i))
    return allCols

def makeFrameAnimation(pathList, height, widthTotal, widthSection):
    allFrames = []
    for path in pathList:
        allFrames.append(makeFrame(path, height, widthTotal, widthSection))
    return allFrames

penisPathList = [
    "C:\\Users\\Public\\Penis\\longpenis_1.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_2.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_3.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_4.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_5.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_6.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_7.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_8.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_9.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_10.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_11.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_10.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_9.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_8.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_7.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_6.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_5.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_4.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_3.bmp",
    "C:\\Users\\Public\\Penis\\longpenis_2.bmp",
]

print "SEX"
print makeFrameAnimation(penisPathList, 8, 80, 8)
#print makeFrame("C:\\Users\\Public\\Penis\\penis_1.bmp", 8, 40, 8)
#allFrames = []
#allCols = []
#for i in range(0,5):
#    allCols.append(processColsPart(getPictureCols("C:\\Users\\Public\\Penis\\penis_1.bmp", 8),  8, i))
#print allCols
print "SEX"

#Split BMP file into pixel rows and process into binary
def makePicture(path,width):
    return processRows(getPictureRows(path, width))

def processBigImage(imag_rows, widthTotal, sections):
    widthSection = widthTotal/sections
    sectionList = []
    for i in range(0,sections):
        sectionList.append(processRowsPart(imag_rows,widthSection,sections-1-i))
    return sectionList

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

def makeScrollAnimation(path, widthTotal, sections):
    frames = []
    imag_rows = getPictureRows("C:\\Users\\Public\\Penis\\penis_1.bmp", widthTotal)
    for i in range(0,20):
        frames.append(processBigImage(imag_rows, widthTotal, sections))
        imag_rows = scrollEachRowOnce(imag_rows)
    return frames

print makeAllPics("C:\\Users\\Public\\Penis\\penis_1.bmp", 40, 5)

print
print

print makePicture("C:\\Users\\Public\\Arial_Letters2\\H.bmp",8)
print
print
print makeRealPicture("C:\\Users\\Public\\Arial_Letters2\\H.bmp",8)
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
#print makeAnimation(penisPathList, 40, 5)
#print
#print makeScrollAnimation("C:\\Users\\Public\\Penis\\penis_1.bmp", 40, 5)
