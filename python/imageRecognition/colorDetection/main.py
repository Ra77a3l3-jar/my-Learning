import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("./forms.jpg")

img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

lower_orange = np.array([5, 150, 150])
upper_orange = np.array([15, 255, 255])

mask = cv2.inRange(img_hsv, lower_orange, upper_orange)

new_img = cv2.bitwise_and(img, img, mask=mask)

plt.imshow(new_img)
plt.show()
