import Image
im = Image.open("C:\\test.bmp")
imag = list(im.getdata())

n = 8
rows = []
roworder = [6, 7, 5, 1, 4, 2, 3, 0]
colorder = [2, 7, 6, 3, 0, 1, 4, 5]

def arrayToBinary(array):
    arraybinary = 0
    position = 1
    for elem in array:
        arraybinary = arraybinary + elem*position
        position = position*2
    return arraybinary

def rotateRows(imag_rows):
    new_imag_rows = []
    for imag_row in imag_rows:
        new_imag_row = imag_row[n-1:]+imag_row[:n-1]
        new_imag_rows.append(new_imag_row)
    #print new_imag_rows
    return new_imag_rows
#print imag_rows

def processRows(imag_rows):
    rows = []
    for imag_row in imag_rows:
        new_imag_row = [ imag_row[i] for i in roworder ]
        #print imag_row, "->", new_imag_row
        rowbinary = arrayToBinary(new_imag_row)
        #print rowbinary
        rows.append(rowbinary)
    return rows

def processRowsPart(imag_rows,index):
    rows = []
    for imag_row in imag_rows:
        imag_row = imag_row[n*index:n*(index+1)]
        new_imag_row = [ imag_row[i] for i in roworder ]
        #print imag_row, "->", new_imag_row
        rowbinary = arrayToBinary(new_imag_row)
        #print rowbinary
        rows.append(rowbinary)
    return rows

def makePicturePart(path,ntot,i):
    im = Image.open(path)
    imag = list(im.getdata())
    imag_rows = []
    while imag:
        imag_row = imag[:ntot]
        imag_rows.append(imag_row)
        imag = imag[ntot:]
    print processRowsPart(imag_rows,i)

def makePicture(path):
    im = Image.open(path)
    imag = list(im.getdata())
    imag_rows = []
    while imag:
        imag_row = imag[:n]
        imag_rows.append(imag_row)
        imag = imag[n:]
    print processRows(imag_rows)

def makeAllPics(path):
    for i in range(0,5):
        makePicturePart(path,40,4-i)

#makePicture("C:\\test.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\H.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\A.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\P.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\P.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\Y.bmp")
print
makePicture("C:\\Users\\Public\\Arial_Letters2\N.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\E.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\W.bmp")
print
makePicture("C:\\Users\\Public\\Arial_Letters2\Y.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\E.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\A.bmp")
makePicture("C:\\Users\\Public\\Arial_Letters2\R.bmp")
print
makePicture("C:\\Users\\Public\\Penis\\penis5.bmp")
makePicture("C:\\Users\\Public\\Penis\\penis4.bmp")
makePicture("C:\\Users\\Public\\Penis\\penis3.bmp")
makePicture("C:\\Users\\Public\\Penis\\penis2.bmp")
makePicture("C:\\Users\\Public\\Penis\\penis1.bmp")
print
makeAllPics("C:\\Users\\Public\\Penis\\penis_1.bmp")
print
makeAllPics("C:\\Users\\Public\\Penis\\penis_2.bmp")
print
makeAllPics("C:\\Users\\Public\\Penis\\penis_3.bmp")
print
makeAllPics("C:\\Users\\Public\\Penis\\penis_4.bmp")
print
makeAllPics("C:\\Users\\Public\\Penis\\penis_5.bmp")
print
makeAllPics("C:\\Users\\Public\\Penis\\penis_6.bmp")
print
makeAllPics("C:\\Users\\Public\\Penis\\penis_7.bmp")

#new_rows = [ rows[i] for i in colorder ]
#print new_rows
