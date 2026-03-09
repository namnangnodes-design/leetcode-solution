function canFinish(numCourses: number, prerequisites: number[][]): boolean {
    // 1. Khởi tạo danh sách kề và mảng bậc vào (in-degree)
    const adj: number[][] = Array.from({ length: numCourses }, () => []);
    const inDegree: number[] = new Array(numCourses).fill(0);

    // 2. Xây dựng đồ thị
    // Với mỗi cặp [a, b], b là môn tiên quyết của a (b -> a)
    for (const [course, pre] of prerequisites) {
        adj[pre].push(course);
        inDegree[course]++;
    }

    // 3. Đưa tất cả các môn không có môn tiên quyết (inDegree === 0) vào queue
    const queue: number[] = [];
    for (let i = 0; i < numCourses; i++) {
        if (inDegree[i] === 0) {
            queue.push(i);
        }
    }

    // 4. Xử lý BFS (Topological Sort)
    let count = 0;
    while (queue.length > 0) {
        const cur = queue.shift()!; // Lấy phần tử đầu tiên
        count++;

        // Duyệt qua các môn học phụ thuộc vào môn hiện tại
        for (const neighbor of adj[cur]) {
            inDegree[neighbor]--; // Giảm số lượng môn tiên quyết cần hoàn thành
            
            // Nếu không còn môn tiên quyết nào, có thể học môn này
            if (inDegree[neighbor] === 0) {
                queue.push(neighbor);
            }
        }
    }

    // 5. Nếu số môn học được bằng tổng số môn ban đầu thì trả về true
    return count === numCourses;
};
