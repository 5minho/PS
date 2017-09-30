//
//  main.swift
//  BOJ14722
//
//  Created by 오민호 on 2017. 9. 30..
//  Copyright © 2017년 Minomi. All rights reserved.
//

import Foundation

let N = Int(readLine()!)!
let NINF = -987654321

var cache = Array(repeating : Array(repeating : [Int](repeating : -1, count : N),
                                    count: N),
                  count : 3)
var milkCity = Array(repeating: [Int](), count: N)

for i in 0 ..< N {
    if let line = readLine() {
        milkCity[i] = line.components(separatedBy: " ").map {
            Int($0)!
        }
    }
}

func outOfBoundary(y : Int, x: Int) -> Bool {
    return y >= N || x >= N
}

func checkFinish(y : Int, x: Int) -> Bool {
    return y == N - 1 && x == N - 1
}

func boolToInt(query : Bool) -> Int {
    return query ? 1 : 0
}

func drinkMilk(y : Int, x: Int, _ currentMilk : Int) -> Int {

    if outOfBoundary(y : y, x : x) {
        return NINF
    }

    if checkFinish(y: y, x: x) {
        return boolToInt(query: currentMilk == milkCity[y][x])
    }
    
    if cache[currentMilk][y][x] != -1 {
        return cache[currentMilk][y][x]
    }
    
    let nextMilk = (currentMilk == milkCity[y][x]) ? (currentMilk + 1) % 3 : currentMilk
    
    cache[currentMilk][y][x] = max(drinkMilk(y: y + 1, x: x, nextMilk),
                                drinkMilk(y: y, x: x + 1, nextMilk)) +
                                boolToInt(query: currentMilk == milkCity[y][x])
    
    return cache[currentMilk][y][x]
    
}

print(drinkMilk(y: 0, x: 0, 0))


