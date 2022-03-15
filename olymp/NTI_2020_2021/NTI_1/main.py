from laser_example import *
print(lazer_analyzer())


from camera_example import *
img = camera_analyzing()
cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()


from square_movement_example import *
tormozit()
go(1, -1,57)
go()


