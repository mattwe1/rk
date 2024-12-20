# Данные числа в двоичной системе
A = "101101"
B = "110011"

# Преобразуем двоичные строки в целые числа
A_int = int(A, 2)
B_int = int(B, 2)
and_result = A_int & B_int
and_result_bin = bin(and_result)[2:]
sum_result = A_int + B_int
sum_result_bin = bin(sum_result)[2:]
print(f"Побитовая операция AND: {and_result_bin}")
print(f"Сумма чисел: {sum_result_bin}")
