import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("./forms.jpg")
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

lower_orange = np.array([5, 150, 150])
upper_orange = np.array([15, 255, 255])

mask = cv2.inRange(img_hsv, lower_orange, upper_orange)

plt.imshow(mask)
plt.show()

kernel = np.ones((5, 5), np.uint8)

mask_clean = cv2.erode(mask, kernel, iterations=1)
mask_clean = cv2.dilate(mask_clean, kernel, iterations=2)

contours, hierarchy = cv2.findContours(mask_clean, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

""" Drawing bounding box """
output = img_rgb.copy()

for cnt in contours:
    area = cv2.contourArea(cnt)
    if area > 500: # filter noise
        x, y, w, h = cv2.boundingRect(cnt)
        cv2.rectangle(output, (x, y), (x + w, y + h), (0, 255, 0), 2)

plt.imshow(output)
plt.show()

# it finds the contours on the masked version and displays the bounding boxes on the rgb version
