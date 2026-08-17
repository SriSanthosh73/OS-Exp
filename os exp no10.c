#include <stdio.h>

int main()
{
    int pageTable[20];
    int pageSize;
    int numPages;
    int logicalAddress;
    int pageNumber;
    int offset;
    int frameNumber;
    int physicalAddress;
    int i;

    // Input page size
    printf("Enter Page Size: ");
    scanf("%d", &pageSize);

    // Input number of pages
    printf("Enter Number of Pages: ");
    scanf("%d", &numPages);

    // Input frame number for each page
    printf("Enter Frame Numbers for Each Page:\n");

    for (i = 0; i < numPages; i++)
    {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    // Input logical address
    printf("Enter Logical Address: ");
    scanf("%d", &logicalAddress);

    // Calculate page number and offset
    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    // Check whether page number is valid
    if (pageNumber >= numPages)
    {
        printf("Invalid Logical Address\n");
        return 0;
    }

    // Get frame number from page table
    frameNumber = pageTable[pageNumber];

    // Calculate physical address
    physicalAddress = (frameNumber * pageSize) + offset;

    // Display results
    printf("\nPage Number       : %d", pageNumber);
    printf("\nOffset            : %d", offset);
    printf("\nFrame Number      : %d", frameNumber);
    printf("\nPhysical Address  : %d\n", physicalAddress);

    return 0;
}