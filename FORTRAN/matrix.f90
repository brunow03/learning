program matrix_multiplication
    implicit none

    integer, parameter :: n = 4
    integer :: i, j, k
    real(8), dimension(n, n) :: A, B, C
    real(8), parameter :: alpha = 1.0d0, beta = 0.0d0

    ! Initialize matrices
    call initialize_matrices(A, B)

    ! Perform matrix multiplication
    call block_matrix_multiply(A, B, C)

    ! Print the result
    call print_matrix(C)

contains

    subroutine initialize_matrices(A, B)
        real(8), dimension(:,:), intent(out) :: A, B
        integer :: i, j

        ! Initialize matrices A and B with example values using loops
        do i = 1, size(A,1)
            do j = 1, size(A,2)
                A(i,j) = real(i + j, kind=8)
                B(i,j) = real(i * j, kind=8)
            end do
        end do
    end subroutine initialize_matrices

    subroutine block_matrix_multiply(A, B, C)
        real(8), dimension(:,:), intent(in) :: A, B
        real(8), dimension(:,:), intent(out) :: C
        integer :: i, j, k, blockSize, iBlock, jBlock, kBlock
        real(8), dimension(size(A,1), size(A,2)) :: temp

        blockSize = 2  ! Define block size

        C = 0.0d0

        do iBlock = 1, size(A,1), blockSize
            do jBlock = 1, size(B,2), blockSize
                do kBlock = 1, size(A,2), blockSize
                    ! Perform the block matrix multiplication
                    do i = iBlock, min(iBlock+blockSize-1, size(A,1))
                        do j = jBlock, min(jBlock+blockSize-1, size(B,2))
                            temp(i,j) = 0.0d0
                            do k = kBlock, min(kBlock+blockSize-1, size(A,2))
                                temp(i,j) = temp(i,j) + A(i,k) * B(k,j)
                            end do
                        end do
                    end do
                    ! Accumulate the results
                    do i = iBlock, min(iBlock+blockSize-1, size(A,1))
                        do j = jBlock, min(jBlock+blockSize-1, size(B,2))
                            C(i,j) = C(i,j) + temp(i,j)
                        end do
                    end do
                end do
            end do
        end do
    end subroutine block_matrix_multiply

    subroutine print_matrix(M)
        real(8), dimension(:,:), intent(in) :: M
        integer :: i, j

        print *, "Matrix:"
        do i = 1, size(M,1)
            do j = 1, size(M,2)
                write(*,'(F8.3)', advance='no') M(i,j)
            end do
            print *, ''  ! Move to the next line after printing one row
        end do
    end subroutine print_matrix

end program matrix_multiplication
