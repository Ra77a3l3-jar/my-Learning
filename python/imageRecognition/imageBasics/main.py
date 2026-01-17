import cv2
import matplotlib.pyplot as plt


def resize_image(image):
    width = int(input("Enter new width: "))
    height = int(input("Enter new height: "))

    return cv2.resize(image, (width, height), interpolation=cv2.INTER_LINEAR)


def crop_image(image):
    y1 = int(input("Enter y1: "))
    y2 = int(input("Enter y2: "))
    x1 = int(input("Enter x1: "))
    x2 = int(input("Enter x2: "))

    return image[y1:y2, x1:x2]


def adjust_brightness(image):
    brightness = float(input("Enter brightness (beta, e.g. 50): "))
    contrast = float(input("Enter contrast (alpha, e.g. 1.5): "))

    return cv2.convertScaleAbs(image, alpha=contrast, beta=brightness)

# Returns a rotated image given an angle
def rotate_image(image):
    angle = float(input("Enter clockwise rotation angle: "))

    (h, w) = image.shape[:2]
    center = (w // 2, h // 2)

    M = cv2.getRotationMatrix2D(center, -angle, 1.0)
    return cv2.warpAffine(image, M, (w, h))


def show_info():
    print("\nImage modification options:")
    print(" rotation")
    print(" cropping")
    print(" resizing")
    print(" brightness")


def apply_choice(choice, image):
    choice = choice.lower()

    if choice == "rotation":
        return rotate_image(image)
    elif choice == "cropping":
        return crop_image(image)
    elif choice == "resizing":
        return resize_image(image)
    elif choice == "brightness":
        return adjust_brightness(image)
    else:
        print("Invalid choice")
        return image


def main():
    while True:
        img_path = input("\nEnter the image path (or 'exit'): ")
        if img_path.lower() == "exit":
            break

        img = cv2.imread(img_path)
        if img is None:
            print("Error: image not found")
            continue

        show_info()
        choice = input("Choose an operation: ")

        new_img = apply_choice(choice, img)

        # Show result
        plt.imshow(cv2.cvtColor(new_img, cv2.COLOR_BGR2RGB))
        plt.axis("off")
        plt.show()

        save = input("Save image? (yes/no): ").lower()
        if save == "yes":
            img_name = input("Enter filename (e.g. output.jpg): ")
            cv2.imwrite(img_name, new_img)
            print("Image saved!")


if __name__ == "__main__":
    main()
