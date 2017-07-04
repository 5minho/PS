import Foundation
let cnt = Double(readLine()!)!
let inputs = readLine()!.components(separatedBy: " ").map(){return Int($0)!}
let max = Double(inputs.max()!)
print(String(format : "%.2f",inputs.map(){return Double($0) / max * 100.0}.reduce(0.0){$0 + $1} / cnt))
