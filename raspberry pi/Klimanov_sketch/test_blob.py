import cv2
import numpy as np
cap = cv2.VideoCapture(0)
# setup detector and parameters
params = cv2.SimpleBlobDetector_Params()
params.filterByColor = False
params.filterByArea = True
params.minArea = 1000
params.maxArea = 30000
params.filterByInertia = False
params.filterByConvexity = False
params.filterByCircularity = True
params.minCircularity = 0.5
params.maxCircularity = 1
det = cv2.SimpleBlobDetector_create(params)
# define blue
lower_blue = np.array([129, 141, 155])
upper_blue = np.array([169, 240, 255])
while True:
    ret, frame = cap.read()
    #frame=cv2.flip(frame, -1)
    imgHSV = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    blueMask = cv2.inRange(imgHSV,lower_blue,upper_blue)
    blur= cv2.blur(blueMask, (5,5))
    res = cv2.bitwise_and(frame, frame, mask=blueMask)
    # get and draw keypoint
    keypnts = det.detect(blur)
    cv2.drawKeypoints(frame, keypnts, frame, (0,0,255),
    cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
    cv2.imshow('frame', frame)
    cv2.imshow('mask', blur)
    for k in keypnts:
        print (k.size)
    ch = cv2.waitKey(5)
    if ch == 27:
        break    
cap.release()
cv2.destroyAllWindows()
