use std::collections::BTreeMap;
use std::io;

struct Score {
    midterm: i32,
    final_exam: i32,
}

fn main() {
    let mut student_scores: BTreeMap<String, Score> = BTreeMap::new();

    let mut input = String::new();
    println!("Enter number of students:");
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let n: usize = input.trim().parse().expect("Please enter a number!");

    for _ in 0..n {
        let mut name = String::new();
        let mut s = Score { midterm: 0, final_exam: 0 };

        println!("Enter student name:");
        io::stdin().read_line(&mut name).expect("Failed to read line");
        let name = name.trim().to_string();

        input.clear();
        println!("Enter midterm score:");
        io::stdin().read_line(&mut input).expect("Failed to read line");
        s.midterm = input.trim().parse().expect("Please enter a number!");

        input.clear();
        println!("Enter final exam score:");
        io::stdin().read_line(&mut input).expect("Failed to read line");
        s.final_exam = input.trim().parse().expect("Please enter a number!");

        student_scores.insert(name, s);
    }

    println!("\nEnter a student name to search:");
    input.clear();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let query = input.trim().to_string();
    match student_scores.get(&query) {
        Some(s) => println!("Midterm Score: {}, Final Exam Score: {}", s.midterm, s.final_exam),
        None => println!("Student not found."),
    }
}
