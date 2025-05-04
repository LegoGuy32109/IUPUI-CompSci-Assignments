# data-structures-assignment3
5-way Btree of integers in C++, returning range of random integers (no repeats) from N - 2*N

*screen recording here: https://youtu.be/_AgjVdK4yNU*

To run the file, type `make` to compile the code to an executable called Btree, which you can then run the executable on command line with `./Btree`. The program will generate a 5-way Btree from random integers [0, 3N]. It then searches the Btree for elements within the range [N, 2N], displaying them to the user. 
When typing in the variable N, it must be >= 400
### Incorrect User Input
```
Enter N to construct 5-way Btree
:-1
N must be >= 400
Enter N to construct 5-way Btree
:20
N must be >= 400
Enter N to construct 5-way Btree
: |
```
### Successful Run:
```
Enter N to construct 5-way Btree
:420
```
*(This works better with word wrap, below is outputted)*

420 421 422 423 . . . . 428 429 . . . 433 . 435 . . . . . . . . 444 445 . . . . . . 452 453 454 . . . . 459 . . . . 464 . 466 467 . . . . . . . . . . . . . . . 483 484 . . 487 488 . . . . . . . . 497 . . . 501 . . . . 506 . . 509 510 511 . 513 . . . . . . 520 . . . 524 . 526 527 528 . 530 531 . . . . . . . . . . . . . . . . 548 . 550 . 552 . . . 556 . . . . . 562 . 564 . 566 . . . 570 . . 573 . . . . . . 580 . 582 583 . . 586 . 588 589 590 591 . . . . 596 . . 599 . . . . . 605 . 607 608 609 . 611 . . 614 . . . . . . 621 622 623 . . . . . . . . . . . . . . . . . . . 643 644 645 . 647 648 649 . . 652 . 654 . 656 657 658 . . 661 662 . . . 666 . 668 669 670 671 . . . 675 676 . . . . . . . 684 . . 687 . 689 . . . . . 695 696 697 . . . . 702 . 704 705 . 707 708 709 710 . . . . . . 717 718 . . . . 723 . . 726 . 728 729 730 . . . . . . . . . . . . . . . . . 748 . 750 751 . . . . . . 758 759 760 761 . . . 765 766 . . . 770 . 772 . . 775 776 . . . 780 781 782 783 784 785 . . 788 . . . . . 794 795 796 . 798 . . . . . . . . 807 808 809 . . . . . . 816 817 818 . . . . . . . 826 827 828 . 830 . . 833 . 835 836 837 838 .
```
% of range (420 elements) covered by keys: 0.338095 (142 keys)
Returned keys:
Key 420 returned
Key 421 returned
Key 422 returned
Key 423 returned
Key 428 returned
Key 429 returned
Key 433 returned
...
Key 837 returned
Key 838 returned
```
I display a chart illustrating where the returned keys are in the range, and give the percentage of keys covered in the range. I then list all of the keys that were returned below for ease of reading. 

You can also compile the program and run it at the same time with  `make run`.
