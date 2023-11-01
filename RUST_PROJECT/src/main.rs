use std::io;

fn main() {
    let mut input = String::new();
    println!("Enter number of rows and columns: ");
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.trim().split_whitespace();
    let rows: usize = iter.next().unwrap().parse().unwrap();
    let cols: usize = iter.next().unwrap().parse().unwrap();

    let mut matrix_a = vec![vec![0; cols]; rows];
    let mut matrix_b = vec![vec![0; cols]; rows];
    let mut result_matrix = vec![vec![0; cols]; rows];

    println!("Enter Matrix A:");
    for i in 0..rows {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let row_values: Vec<i32> = input.trim().split_whitespace().map(|n| n.parse().unwrap()).collect();
        for j in 0..cols {
            matrix_a[i][j] = row_values[j];
        }
    }

    println!("Enter Matrix B:");
    for i in 0..rows {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let row_values: Vec<i32> = input.trim().split_whitespace().map(|n| n.parse().unwrap()).collect();
        for j in 0..cols {
            matrix_b[i][j] = row_values[j];
        }
    }

    for i in 0..rows {
        for j in 0..cols {
            result_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    println!("Result Matrix:");
    for i in 0..rows {
        for j in 0..cols {
            print!("{} ", result_matrix[i][j]);
        }
        println!();
    }
}
