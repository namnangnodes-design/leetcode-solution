/**
 * class Robot {
 *      // Returns true if the cell in front is open and robot moves into the cell.
 *      // Returns false if the cell in front is blocked and robot stays in the current cell.
 * 		move(): boolean {}
 * 		
 *      // Robot will stay in the same cell after calling turnLeft/turnRight.
 *      // Each turn will be 90 degrees.
 * 		turnRight() {}
 * 		
 *      // Robot will stay in the same cell after calling turnLeft/turnRight.
 *      // Each turn will be 90 degrees.
 * 		turnLeft() {}
 * 		
 * 		// Clean the current cell.
 * 		clean(): {}
 * }
 */

const DIRECTIONS = [[1,0], [0, 1], [-1, 0], [0, -1]]; // Forward, Right, Backward, Left

/**
 * This function determines the next spot to visit and turns the robot to face it.
 * It DOES NOT MOVE THE ROBOT. Just turns it.
 * If there is no new spot to visit, it will point the robot to backtrack.
 */
function turn(robot: Robot, currX: number, currY: number, direction: number, visited: Record<string, boolean>, moveStack: string[], shouldVisit: Set<string>) {
    let newDir = -1;
    let newX = 0;
    let newY = 0;
    let foundDir = false;
    for (let i = 0; i < 4; i++) {
        // Start with the direction we're facing to minimize turns
        const dirCheck = DIRECTIONS[(i + direction) % 4];
        const xDir = currX + dirCheck[0];
        const yDir = currY + dirCheck[1];
        const dirCheckStr = `${xDir}:${yDir}`

        // If you haven't visited this spot before:
        if (!visited[dirCheckStr]) {
            // Add it to the places TO visit
            shouldVisit.add(dirCheckStr);

            // If you haven't already found your next direction,
            // mark this as your next direction.
            if (!foundDir) {
                newDir = i;
                newX = xDir;
                newY = yDir;
                foundDir = true;
            }
        } else if (moveStack.length > 0 && moveStack[moveStack.length - 1] === dirCheckStr) {
            // If you haven't found a forward direction yet, set your direction to
            // backtrack.
            if (!foundDir) {
                newDir = i; 
                newX = xDir;
                newY = yDir;
            }
        }
    }

    // Direction 3 is left, so it's easier to go left than right 3 times.
    if (newDir === 3) {
        robot.turnLeft();
    } else if (newDir === 2 || newDir == 1) {
        // 1 and 2 are both turning right
        robot.turnRight();
        if (newDir === 2) {
            // but 2 is turning right twice (go backwards)
            robot.turnRight();
        }
    }

    return [newX, newY, (newDir + direction) % 4];
}

function cleanRoom(robot: Robot) {
    let visited: Record<string, boolean> = {};
    let shouldVisit = new Set<string>(['0:0']);
    let moveStack: string[] = [];
    let x = 0;
    let y = 0;
    let dir = 0; // 0 = Forward, 1 = Right, 2 = Backward, 3 = Left
    while (shouldVisit.size > 0) {
        const currLocStr = `${x}:${y}`;
        // If you haven't already visited this location:
        if (!visited[currLocStr]) {
            robot.clean();                  // Clean it
            shouldVisit.delete(currLocStr); // Remove it from the places you should visit
            visited[currLocStr] = true;     // Set it to visited
        }

        // Find the next spot you need to go and turn towards it
        const [newX, newY, newDir] = turn(robot, x, y, dir, visited, moveStack, shouldVisit);
        const newLocStr = `${newX}:${newY}`;

        // If you CAN move
        if (robot.move()) {
            // If you are backtracking, pop the record off the move stack
            // Otherwise, push your current location ON the move stack
            if (moveStack.length && moveStack[moveStack.length - 1] === newLocStr) {
                moveStack.pop();
            } else {
                moveStack.push(currLocStr);
            }
            x = newX;
            y = newY;
        } else {
            // If you CAN'T move, mark that new location as visited, and
            // delete it from the places you should visit.
            visited[newLocStr] = true;
            shouldVisit.delete(newLocStr);
        }

        // Set your direction to the direction the robot is now facing.
        dir = newDir;
    }
};
