function canSeePersonsCount(heights: number[]): number[] {
    const n = heights.length;
    const result: number[] = new Array(n).fill(0);
    const stack: number[] = []; // Lưu trữ chiều cao giảm dần từ dưới lên

    // Duyệt từ phải sang trái
    for (let i = n - 1; i >= 0; i--) {
        let count = 0;
        const currentHeight = heights[i];

        // 1. Những người trong stack thấp hơn người hiện tại
        // Người hiện tại chắc chắn nhìn thấy họ
        while (stack.length > 0 && currentHeight > stack[stack.length - 1]) {
            stack.pop();
            count++;
        }

        // 2. Nếu stack vẫn còn phần tử, nghĩa là người hiện tại 
        // nhìn thấy thêm 1 người cao hơn mình đứng ngay sau
        if (stack.length > 0) {
            count++;
        }

        // Lưu kết quả và đẩy chiều cao hiện tại vào stack
        result[i] = count;
        stack.push(currentHeight);
    }

    return result;
};
