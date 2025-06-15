#include "ProductManagementView.h"

ProductManagementView::ProductManagementView() {
    setTitle("제품 관리");
    setMenuItems({
        "제품 조회",
        "제품 입력",
        "제품 수정",
        "제품 삭제"
    });
    setMenuActions({

    });
} 