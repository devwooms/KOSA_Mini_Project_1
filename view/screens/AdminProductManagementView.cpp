#include "AdminProductManagementView.h"

#include <iostream>

#include "../../controller/ScreenController.h"
#include "AdminProductAddView.h"
#include "AdminProductDeleteView.h"
#include "AdminProductEditView.h"
#include "AdminProductListView.h"

AdminProductManagementView::AdminProductManagementView()
{
    setErrorMessages({
        " ",
        "잘못된 입력입니다. 다시 선택하세요.",
    });
    setTitle("제품 관리");
    setMenuItems({"제품 조회", "제품 입력", "제품 수정", "제품 삭제"});
    setMenuActions({[this]()
                    {
                        // 제품 조회 화면으로 이동
                        goToScreen(std::make_shared<AdminProductListView>());
                    },
                    [this]()
                    {
                        // 제품 입력 화면으로 이동
                        goToScreen(std::make_shared<AdminProductAddView>());
                    },
                    [this]()
                    {
                        // 제품 수정 화면으로 이동
                        goToScreen(std::make_shared<AdminProductEditView>());
                    },
                    [this]()
                    {
                        // 제품 삭제 화면으로 이동
                        goToScreen(std::make_shared<AdminProductDeleteView>());
                    }});
}

int AdminProductManagementView::getUserChoice()
{
    int choice;
    std::cout << "선택하세요 (0: 뒤로가기, 1~" << getMenuItems().size() << "): ";

    if (std::cin >> choice)
    {
        // 입력 버퍼 비우기
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // 유효한 입력인지 확인
        if (choice >= 0 && choice <= static_cast<int>(getMenuItems().size()))
        {
            return choice;
        }
    }
    else
    {
        // 잘못된 입력 처리
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // 잘못된 입력의 경우 -1 반환
    return -1;
}

void AdminProductManagementView::run()
{
    while (true)
    {
        // 화면 지우기
        clearScreen();

        // 에러 메시지 표시
        renderErrorMessages(getErrorMessages()[getShowError()]);

        // 타이틀 표시
        renderTitle(getTitle());

        // 메뉴 표시
        renderMenuItems(getMenuItems());

        // 사용자 입력 받기
        int choice = getUserChoice();

        // 선택 처리
        if (choice == -1)
        {
            // 잘못된 입력 - 에러 플래그 설정하고 다시 루프
            setShowError(1);
            continue;
        }
        else if (choice == 0)
        {
            // 뒤로가기 - 스택에서 제거하여 이전 화면으로
            goBack();
            break;
        }
        else if (choice > 0 && choice <= static_cast<int>(getMenuItems().size()))
        {
            // 생성자에서 설정한 menuActions 활용
            const auto& actions = getMenuActions();
            if (choice <= actions.size() && actions[choice - 1])
            {
                actions[choice - 1]();  // 설정된 액션 실행
                break;                  // 액션 실행 후 루프 종료
            }
        }
    }
}