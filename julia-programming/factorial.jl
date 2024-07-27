# Function to compute the factorial of a number
function factorial(n::Int)
    if n < 0
        error("Factorial is not defined for negative numbers")
    elseif n == 0
        return 1
    else
        result = 1
        for i in 1:n
            result *= i
        end
        return result
    end
end

# Print factorials of numbers from 1 to 10
for num in 1:10
    println("Factorial of $num is $(factorial(num))")
end
