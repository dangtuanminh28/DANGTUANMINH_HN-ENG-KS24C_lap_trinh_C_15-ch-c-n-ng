#include <stdio.h>
int main() {
	// Khai bao mang
    int arr[100]; 
    int size = 0; 
    int choice, temp, max, min, max_a, min_a; 
	int sum = 0; 
	int index = 0;
    do {
    // In menu ra ngoai man hinh
    printf("\n MENU \n");
    printf("1.Nhap so phan tu va gia tri cho mang\n");
	printf("2.In ra gia tri cac phan tu trong mang\n");
	printf("3.Dem so luong hoan hao\n");
	printf("4.Dem so luong so nguyen to\n");
	printf("5.Tim gia tri lon thu hai trong mang\n");
	printf("6.Tim gia tri nho thu hai trong mang\n");
	printf("7.Them phan tu tai vi tri\n");
	printf("8.Xoa phan tu tai vi tri\n");
	printf("9.Sap xep mang theo thu tu tang dan\n");
	printf("10.Sap xep mang theo thu tu giam dan\n");
	printf("11.Tim kiem phan tu(tim kiem nhi phan)\n");
	printf("12.Xoa phan tu trung lap va in phan tu doc nhat\n");
	printf("13.Sap xep va hien thi so chan dung truoc, so le dung sau\n");
	printf("14.Dao nguoc mang\n");
	printf("15.Thoat\n");
	printf("Lua chon cua ban:");
	// Gia tri nhap vao tu nguoi dung
	scanf("%d", &choice);
        switch (choice) {
            // Nhap so phan tu va gia tri cho mang
			case 1:
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &size);
                if (size <= 0 || size > 100) {
                    printf("So phan tu khong hop le!\n");
                    size = 0;
                } else {
                    for (int i = 0; i < size; i++) {
                        printf("Nhap gia tri phan tu arr[%d]: ", i);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            // In ra gia tri cac phan tu trong mang
			case 2: 
                if (size == 0) {
                    printf("Mang rong!\n");
                } else {
                    printf("Cac phan tu trong mang la: ");
                    for (int i = 0; i < size; i++) {
                        printf("arr[%d] = %d, ", i, arr[i]);
                    }
                    printf("\n");
                }
                break;
            // Dem so luong so hoan hao
            case 3:
            	if (size == 0) {
                    printf("Mang rong!\n");
                } else {
                	printf("Cac phan tu so hoan hao co trong mang la: ");
                	for (int i = 1; i < size; i++) {
                		sum = 0;
                		for (int a = 1; a < size; a++) {
                			if(arr[i] % a == 0) {
                			sum = sum + i;
							}
                		}
                			if(sum == arr[i]){
							index++;	
							}
						}
						printf("Co %d la so hoan hao", index);
					break;
				}
            // Dem so luong so nguyen to
			case 4: 
                if (size == 0) {
                    printf("Mang rong!\n");
                } else {
                    printf("Cac phan tu so nguyen to co trong mang la: ");
                    for (int i = 0; i < size; i++) {
                        int so_nguyen_to = 1;
                        if (arr[i] <= 1) so_nguyen_to = 0;
                        for (int j = 2; j * j <= arr[i]; j++) {
                            if (arr[i] % j == 0) {
                                so_nguyen_to = 0;
                                break;
                            }
                        }
                        if (so_nguyen_to) {
                            printf("%d ", arr[i]);
                        }
                    }
                    printf("\n");
                }
                break;
            // Tim gia tri lon thu hai trong mang
			case 5:
				if (size == 0) {
                    printf("Mang rong!\n");
                } else {
            	max=arr[0];
            	for(int i=0;i<size;i++){
            		if(arr[i]>max) {
            			max_a=max;
						max=arr[i];
            		} else if(arr[i]>max_a) {
            			max_a=arr[i];
            		}
				}
				printf("Gia tri lon nhat trong mang thu hai la: %d", max_a);
            	break;
				}
            // Tim gia tri nho thu hai trong mang
            case 6:
            	if (size >= 100) {
                    printf("Mang rong!\n");
                } else {
                min=arr[0];
            	for(int i=0;i<size;i++){
            		if(arr[i]<min) {
            			min_a=min;
						min=arr[i];
            		} else if(arr[i]<min_a) {
            			min_a=arr[i];
            		}
				}
            	printf("Gia tri nho nhat trong mang thu hai la: %d", min_a);
            	break;
				}
            // Them phan tu vao vi tri
			case 7:
                if (size > 100) {
                    printf("Mang da day! Khong the them phan tu!\n");
                } else {
                    int value;
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    arr[size] = value;
                    size++;
                    printf("Da them %d vao mang.\n", value);
                break;
                }
            // Xoa phan tu tai vi tri
			case 8: 
                if (size == 0) {
                    printf("Mang rong, khong co phan tu de xoa!\n");
                } else {
                    int index;
                    printf("Nhap vi tri can xoa (0 - %d): ", size - 1);
                    scanf("%d", &index);
                    if (index < 0 || index >= size) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = index; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Da xoa phan tu tai vi tri %d.\n", index);
                    }
                }
                break;
            // Sap xep mang theo thu tu tang dan
            case 9:
            	if (size == 0) {
                    printf("Mang rong!\n");
                } else {
                	for(int i=0;i <size-1;i++) {
						for(int j=0;j<size-i-1;j++) {
							if(arr[j]>arr[j+1]) {
								temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
							}
						}
					} 
					for(int i=0;i<size;i++) {
						printf("%d ",arr[i]);	
					}
					break;
				}
            // Sap xep mang theo thu tu giam dan
            case 10:
			if (size == 0) {
                    printf("Mang rong!\n");
                } else {
			for(int i=0;i<size-1;i++) {
				for(int j=0;j<size-i-1;j++) {
					if(arr[j]<arr[j+1]) {
						temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}
				}
			} 
			for(int i=0;i<size;i++) {
				printf("%d ",arr[i]);	
			}
			break;
			}                                                                
			// Tim kiem phan tu
            case 11:
            	if (size == 0) {
                    printf("Mang rong!\n");
                } else {
                    int flag=-1;
	 				printf("Moi nhap gia tri muon kiem tra:");
	 				scanf("%d", &temp);
				 	for( int i = 0;i < size;i++) {
	 					if (arr[i]==temp){
	 						printf("Gia tri %d nam o vi tri %d\n",temp,i);
	 						flag++;
		 				}
	 				}
	 			if (flag==-1){
	 	 			printf("Gia tri da nhap khong co trong mang\n");
	 			}
	 			break;
				}
			// Xoa phan tu trung lap va in phan tu doc nhat
			case 12:
				if (size == 0) {
                    printf("Mang rong!\n");
                } else {
                	for (int i = 0; i < size; i++) {
        			for (int j = i + 1; j < size;) {
           				 if (arr[i] == arr[j]) {
                			for (int k = j; k < size - 1; k++) {
                    			arr[k] = arr[k + 1];
                			}
                			size--;
            			} else {
                			j++;
            			}
        			}
    			}
    			printf("Da xoa cac phan tu trung lap trong mang.\n");
    			break;
            }
			// Sap xep va hien thi so chan dung truoc le dung sau
			case 13:
				if (size == 0) {
                    printf("Mang rong!\n");
                } else {
					for (int i = 0; i < size; i++) {
        				for (int j = i + 1; j < size; j++) {
            				if (arr[i] % 2 == 1 && arr[j] % 2 == 0) {
                				temp = arr[i];
                				arr[i] = arr[j];
                				arr[j] = temp;
            				}
        				}
    				}
    				printf("Mang sau khi sap xep so chan truoc, so le sau: ");
    				for (int i = 0; i < size; i++) {
        				printf("%d ", arr[i]);
    				}
    				printf("\n");
   	 				break;
					}
			// Dao nguoc mang
			case 14:
				if (size == 0) {
                    printf("Mang rong!\n");
                } else {
				for(int i=0;i<size/2;i++) {
					temp=arr[i];
					arr[i]=arr[size-i-1];
					arr[size-i-1]=temp;
				}
				for(int i=0;i<size;i++) {
					printf("%d ",arr[i]);
				}
				break;
				}
            // Thoat chuong trinh
			case 15:
                printf("Ket thuc chuong trinh.\n");
                break;
            default: {
                printf("Lua chon khong hop le!\n");
                break;
            }
        }
    } while (choice != 15);
    return 0;
}

