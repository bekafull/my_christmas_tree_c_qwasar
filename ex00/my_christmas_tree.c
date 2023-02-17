
#include <stdio.h>

int get_max_star_no(int total_layer_no){
    int max_star_no = 7;
    int step = 2;

    for(int i = 2; i <= total_layer_no;i++){
        int lines_no = i + 4 - 1;
        for(int j = 2; j <= lines_no;j++){
            max_star_no += 2;
        }

        max_star_no -= step;

        if(i + 1 != 2 && (i + 1) % 2 == 0){
            step += 2;
        }
    }
    return max_star_no;
}

int get_max_space_no(int total_layer_no){
    int max_star_no = get_max_star_no(total_layer_no);
    return max_star_no / 2;
}

int print_symbol(char sym, int no){
    for(int i = 0; i < no;i++){
        printf("%c",sym);
    }
}

int print_layer(int layer_index, int first_line_star_no, int max_space){
    int current_line_star_no = first_line_star_no;
    int lines_no = layer_index + 4 - 1;

    for(int i = 1; i <= lines_no;i++){
        int space_no = max_space - (current_line_star_no / 2);
        print_symbol(' ', space_no);
        print_symbol('*', current_line_star_no);
        printf("\n");

        current_line_star_no += 2;
    }

    return current_line_star_no - 2;
}

int print_body(int total_layer_no){
    int max_space = get_max_space_no(total_layer_no);
    int current_star_no = 1;
    int step = 2;
    for(int i = 1; i <= total_layer_no;i++){
        current_star_no = print_layer(i, current_star_no, max_space);
        if(i + 1 != 2 && (i + 1) % 2 == 0){
            step += 2;
        }
        current_star_no -= step;
    }

    return 0;
}

int print_base(int total_layer_no){
    int max_space = get_max_space_no(total_layer_no);
    int space_no = max_space - (total_layer_no / 2);

    if(total_layer_no % 2 == 0){
        space_no += 1;
    }

    for(int i = 1; i <= total_layer_no;i++){
        print_symbol(' ', space_no);
        print_symbol('|', total_layer_no);
        printf("\n");
    }
    return 0;
}

int print_tree(int total_layer_no){
    print_body(total_layer_no);
    print_base(total_layer_no);
}

int main(int ac, char** av){

    if(ac > 1){
        int layers = av[1][0] - '0';
        if(layers >  0){
            print_tree(layers);
        }
    }
    return 0;
}