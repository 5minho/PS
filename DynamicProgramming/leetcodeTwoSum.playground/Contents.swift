//: Playground - noun: a place where people can play

import UIKit

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var cache = [Int:Int]()
        for i in 0 ..< nums.count {
            let rightValue = target - nums[i]
            
            if let idx = cache[rightValue] {
                return [idx, i]
            } else {
                cache[nums[i]] = i
            }
            
        }
        return []
    }
}
