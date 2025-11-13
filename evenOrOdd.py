def check_numbers(mode):
    if mode == 'list':
        numberOfEvens = 0
        numberOfOdds = 0
        while True:
            numbers = input("\nEnter numbers separated by spaces: ").strip().split()
            results = []
            valid_input = True
            for num in numbers:
                try:
                    val = float(num)
                except ValueError:
                    print("\nInvalid input. Please enter numbers only.")
                    valid_input = False
                    break
                if int(val) % 2 == 0:
                    results.append("\nEven")
                else:
                    results.append("\nOdd")
            if valid_input:
                for result in results:
                    if result == "\nEven":
                        numberOfEvens += 1
                    else:
                        numberOfOdds += 1
                break
        print(f"\nNumber of evens: {numberOfEvens}")
        print(f"\nNumber of odds: {numberOfOdds}")
    elif mode == 'single':
        while True:
            num = input("\nEnter a number: ").strip()
            try:
                val = float(num)
                if int(val) % 2 == 0:
                    print("\nEven")
                else:
                    print("\nOdd")
                break
            except ValueError:
                print("\nInvalid input. Please enter a number.")


while True:
    listOrSingle = input("\nEnter 'list' to check multiple numbers or 'single' to check one number: ").strip().lower()
    check_numbers(listOrSingle)
    again = input("\nDo you want to check again? (yes/no): ").strip().lower()
    if again != 'yes' and again != 'y':
        break