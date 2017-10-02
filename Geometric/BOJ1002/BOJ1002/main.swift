//
//  main.swift
//  BOJ1002
//
//  Created by 오민호 on 2017. 10. 2..
//  Copyright © 2017년 Minomi. All rights reserved.
//

import Foundation

extension Int {
    var square : Int {
        return self * self
    }
    
    var abs : Int {
        return self > 0 ? self : -self
    }
}

struct Point {
    let x : Int
    let y : Int
    
    init(x : Int, y : Int) {
        self.x = x
        self.y = y
    }
}

struct Circle {
    let x : Int
    let y : Int
    let r : Int
    
    var origin : Point {
        return Point(x: x, y: y)
    }
    
    init(x : Int, y : Int, r : Int) {
        self.x = x
        self.y = y
        self.r = r
    }

    func distance(to point : Point) -> Double {
        return Double((x - point.x).square + (y - point.y).square).squareRoot()
    }
    
    static func== (left : Circle, right : Circle) -> Bool {
        return (left.x == right.x) && (left.y == right.y) && (left.r == right.r)
    }
    
}

let N = Int(readLine()!)!

for _ in 0 ..< N {
    
    let test = readLine()?.components(separatedBy: " ").map {
        Int($0)!
    }
    
    let c1 = Circle(x: test![0], y: test![1], r: test![2])
    let c2 = Circle(x: test![3], y: test![4], r: test![5])
    
    if(c1 == c2) {
        print("-1")
        continue
    }

    let distance = Double(c1.distance(to: c2.origin))
    let sumRadius = Double(c1.r + c2.r)
    let diffRadius = Double((c1.r - c2.r).abs)
    
    if sumRadius > distance && diffRadius < distance {
        print("2")
    } else if sumRadius == distance || diffRadius == distance {
        print("1")
    } else  {
        print("0")
    }
    
}




