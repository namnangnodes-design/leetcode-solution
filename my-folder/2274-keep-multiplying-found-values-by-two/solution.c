int findFinalValue(int* nums, int numsSize, int original) {
for (int i = 0; i < numsSize - 1; i++) {
        bool swap = false;
        // Phần tử lớn nhất sẽ nổi lên vị trí cuối đã sắp xếp sau mỗi lần lặp ngoài
        for (int j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                // HOÁN ĐỔI GIÁ TRỊ ĐÚNG
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp; // Đã sửa: Gán giá trị temp (int)
                swap = true;
            }
        }
        if (swap == false) break; // Mảng đã được sắp xếp, dừng lại sớm
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == original) original *= 2;
    }
    return original;
}
