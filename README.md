메인 메뉴
├── 1. 로그인
│   ├── 1.1 소비자
│   │   └── 1.1.1 제품 검색
│   └── 1.2 관리자
│       ├── 1.2.1 제품 관리
│       │   ├── 1.2.1.1 제품 조회
│       │   │   └── 제품 목록 표시
│       │   ├── 1.2.1.2 제품 입력
│       │   │   └── 새로운 제품 입력 기능
│       │   ├── 1.2.1.3 제품 수정
│       │   │   └── 기존 제품 정보 수정
│       │   └── 1.2.1.4 제품 삭제
│       │       └── 제품 삭제 기능
│       └── 1.2.2 재고 관리
│           ├── 1.2.2.1 재고 조회
│           │   └── 현재 재고 현황 표시
│           ├── 1.2.2.2 재고 입력
│           │   └── 새로운 재고 입력
│           └── 1.2.2.3 재고 증가/차감
│               └── 재고 수량 수정
└── 2. 회원가입
    └── 2.1 회원가입 기능


# 클래스 상속 구조 다이어그램

graph TD
    %% 추상 클래스들
    BaseController["BaseController<br/>(Abstract)"]
    BaseScreenView["BaseScreenView<br/>(Abstract)"]
    
    %% Controller 계층
    UserController["UserController"]
    ProductController["ProductController"]
    InventoryController["InventoryController"]
    ScreenController["ScreenController<br/>(Navigation)"]
    
    %% Model 계층
    User["User<br/>(Model)"]
    Product["Product<br/>(Model)"]
    Inventory["Inventory<br/>(Model)"]
    
    %% Data 계층
    CsvRepository["CsvRepository<br/>(Data Access)"]
    
    %% Auth Views
    HomeView["HomeView"]
    LoginView["LoginView"]
    SignupView["SignupView"]
    
    %% Admin Main Views
    AdminMainView["AdminMainView"]
    
    %% Admin Inventory Views
    AdminInventoryManagementView["AdminInventoryManagementView"]
    AdminInventoryAddView["AdminInventoryAddView"]
    AdminInventoryListView["AdminInventoryListView"]
    AdminInventoryModifyView["AdminInventoryModifyView"]
    
    %% Admin Product Views
    AdminProductManagementView["AdminProductManagementView"]
    AdminProductAddView["AdminProductAddView"]
    AdminProductEditView["AdminProductEditView"]
    AdminProductDeleteView["AdminProductDeleteView"]
    AdminProductListView["AdminProductListView"]
    
    %% Customer Views
    CustomerView["CustomerView"]
    CustomerSearchView["CustomerSearchView"]
    
    %% 상속 관계 (Controller)
    BaseController --> UserController
    BaseController --> ProductController
    BaseController --> InventoryController
    
    %% 상속 관계 (View)
    BaseScreenView --> HomeView
    BaseScreenView --> LoginView
    BaseScreenView --> SignupView
    BaseScreenView --> AdminMainView
    BaseScreenView --> AdminInventoryManagementView
    BaseScreenView --> AdminInventoryAddView
    BaseScreenView --> AdminInventoryListView
    BaseScreenView --> AdminInventoryModifyView
    BaseScreenView --> AdminProductManagementView
    BaseScreenView --> AdminProductAddView
    BaseScreenView --> AdminProductEditView
    BaseScreenView --> AdminProductDeleteView
    BaseScreenView --> AdminProductListView
    BaseScreenView --> CustomerView
    BaseScreenView --> CustomerSearchView
    
    %% 의존성 관계
    UserController -.-> User
    ProductController -.-> Product
    InventoryController -.-> Inventory
    BaseController -.-> CsvRepository
    BaseScreenView -.-> ScreenController
    
    %% 스타일링
    classDef abstract fill:#ffcccc,stroke:#ff6666,stroke-width:3px
    classDef controller fill:#cce5ff,stroke:#0066cc,stroke-width:2px
    classDef view fill:#ccffcc,stroke:#00cc00,stroke-width:2px
    classDef model fill:#ffffcc,stroke:#cccc00,stroke-width:2px
    classDef data fill:#e6ccff,stroke:#9933ff,stroke-width:2px
    classDef navigation fill:#ffd9b3,stroke:#ff8000,stroke-width:2px
    
    class BaseController,BaseScreenView abstract
    class UserController,ProductController,InventoryController controller
    class HomeView,LoginView,SignupView,AdminMainView,AdminInventoryManagementView,AdminInventoryAddView,AdminInventoryListView,AdminInventoryModifyView,AdminProductManagementView,AdminProductAddView,AdminProductEditView,AdminProductDeleteView,AdminProductListView,CustomerView,CustomerSearchView view
    class User,Product,Inventory model
    class CsvRepository data
    class ScreenController navigation

# 디렉토리 구조 다이어그램

graph TD
    Root["KOSA_MiniProject01<br/>(Root)"]
    
    %% 디렉토리들
    ModelDir["model/"]
    ControllerDir["controller/"]
    ViewDir["view/"]
    ScreensDir["screens/"]
    DataDir["data/"]
    
    %% 메인 파일들
    MainCpp["main.cpp"]
    UtilH["util.h"]
    UtilCpp["util.cpp"]
    CMakeLists["CMakeLists.txt"]
    
    %% Model 파일들
    UserH["User.h"]
    UserCpp["User.cpp"]
    ProductH["Product.h"]
    ProductCpp["Product.cpp"]
    InventoryH["Inventory.h"]
    InventoryCpp["Inventory.cpp"]
    
    %% Controller 파일들
    BaseControllerH["BaseController.h"]
    BaseControllerCpp["BaseController.cpp"]
    UserControllerH["UserController.h"]
    UserControllerCpp["UserController.cpp"]
    ProductControllerH["ProductController.h"]
    ProductControllerCpp["ProductController.cpp"]
    InventoryControllerH["InventoryController.h"]
    InventoryControllerCpp["InventoryController.cpp"]
    ScreenControllerH["ScreenController.h"]
    ScreenControllerCpp["ScreenController.cpp"]
    
    %% View 파일들
    BaseScreenViewH["BaseScreenView.h"]
    BaseScreenViewCpp["BaseScreenView.cpp"]
    
    %% Data 파일들
    CsvRepositoryH["CsvRepository.h"]
    CsvRepositoryCpp["CsvRepository.cpp"]
    UserCsv["user.csv"]
    ProductCsv["product.csv"]
    InventoryCsv["inventory.csv"]
    
    %% Screen 파일들 (일부만 표시)
    HomeViewFiles["HomeView.h/cpp"]
    LoginViewFiles["LoginView.h/cpp"]
    AdminMainViewFiles["AdminMainView.h/cpp"]
    ScreenViewFiles["... 16개 화면 클래스들"]
    
    %% 연결
    Root --> ModelDir
    Root --> ControllerDir
    Root --> ViewDir
    Root --> DataDir
    Root --> MainCpp
    Root --> UtilH
    Root --> UtilCpp
    Root --> CMakeLists
    
    ModelDir --> UserH
    ModelDir --> UserCpp
    ModelDir --> ProductH
    ModelDir --> ProductCpp
    ModelDir --> InventoryH
    ModelDir --> InventoryCpp
    
    ControllerDir --> BaseControllerH
    ControllerDir --> BaseControllerCpp
    ControllerDir --> UserControllerH
    ControllerDir --> UserControllerCpp
    ControllerDir --> ProductControllerH
    ControllerDir --> ProductControllerCpp
    ControllerDir --> InventoryControllerH
    ControllerDir --> InventoryControllerCpp
    ControllerDir --> ScreenControllerH
    ControllerDir --> ScreenControllerCpp
    
    ViewDir --> BaseScreenViewH
    ViewDir --> BaseScreenViewCpp
    ViewDir --> ScreensDir
    
    ScreensDir --> HomeViewFiles
    ScreensDir --> LoginViewFiles
    ScreensDir --> AdminMainViewFiles
    ScreensDir --> ScreenViewFiles
    
    DataDir --> CsvRepositoryH
    DataDir --> CsvRepositoryCpp
    DataDir --> UserCsv
    DataDir --> ProductCsv
    DataDir --> InventoryCsv
    
    %% 스타일링
    classDef directory fill:#e1f5fe,stroke:#0277bd,stroke-width:2px
    classDef cppFile fill:#fff3e0,stroke:#f57c00,stroke-width:1px
    classDef headerFile fill:#f3e5f5,stroke:#7b1fa2,stroke-width:1px
    classDef dataFile fill:#e8f5e8,stroke:#2e7d32,stroke-width:1px
    classDef mainFile fill:#ffebee,stroke:#c62828,stroke-width:2px
    
    class ModelDir,ControllerDir,ViewDir,ScreensDir,DataDir directory
    class UserCpp,ProductCpp,InventoryCpp,BaseControllerCpp,UserControllerCpp,ProductControllerCpp,InventoryControllerCpp,ScreenControllerCpp,BaseScreenViewCpp,CsvRepositoryCpp,UtilCpp cppFile
    class UserH,ProductH,InventoryH,BaseControllerH,UserControllerH,ProductControllerH,InventoryControllerH,ScreenControllerH,BaseScreenViewH,CsvRepositoryH,UtilH headerFile
    class UserCsv,ProductCsv,InventoryCsv dataFile
    class MainCpp,CMakeLists mainFile

# 상세 화면 흐름 다이어그램

graph TD
    Main["main.cpp<br/>프로그램 시작"]
    Home["HomeView<br/>메인 화면"]
    
    %% 인증 흐름
    Login["LoginView<br/>로그인"]
    Signup["SignupView<br/>회원가입"]
    
    %% 관리자 흐름
    AdminMain["AdminMainView<br/>관리자 메뉴"]
    
    %% 제품 관리
    ProductMgmt["AdminProductManagementView<br/>제품 관리 메뉴"]
    ProductList["AdminProductListView<br/>제품 조회"]
    ProductAdd["AdminProductAddView<br/>제품 추가"]
    ProductEdit["AdminProductEditView<br/>제품 수정"]
    ProductDelete["AdminProductDeleteView<br/>제품 삭제"]
    
    %% 재고 관리
    InventoryMgmt["AdminInventoryManagementView<br/>재고 관리 메뉴"]
    InventoryList["AdminInventoryListView<br/>재고 조회"]
    InventoryAdd["AdminInventoryAddView<br/>재고 추가"]
    InventoryModify["AdminInventoryModifyView<br/>재고 수정"]
    
    %% 고객 흐름
    Customer["CustomerView<br/>고객 메뉴"]
    CustomerSearch["CustomerSearchView<br/>제품 검색"]
    
    %% 흐름 연결
    Main --> Home
    Home --> Login
    Home --> Signup
    
    Login --> AdminMain
    Login --> Customer
    
    AdminMain --> ProductMgmt
    AdminMain --> InventoryMgmt
    
    ProductMgmt --> ProductList
    ProductMgmt --> ProductAdd
    ProductMgmt --> ProductEdit
    ProductMgmt --> ProductDelete
    
    InventoryMgmt --> InventoryList
    InventoryMgmt --> InventoryAdd
    InventoryMgmt --> InventoryModify
    
    Customer --> CustomerSearch
    
    %% 뒤로가기 연결 (일부만 표시)
    AdminMain -.-> Home
    ProductMgmt -.-> AdminMain
    InventoryMgmt -.-> AdminMain
    Customer -.-> Home
    
    %% 스타일링
    classDef mainFlow fill:#ffcdd2,stroke:#d32f2f,stroke-width:3px
    classDef authFlow fill:#f8bbd9,stroke:#e91e63,stroke-width:2px
    classDef adminFlow fill:#c8e6c9,stroke:#4caf50,stroke-width:2px
    classDef productFlow fill:#dcedc8,stroke:#8bc34a,stroke-width:2px
    classDef inventoryFlow fill:#fff3c4,stroke:#ffeb3b,stroke-width:2px
    classDef customerFlow fill:#bbdefb,stroke:#2196f3,stroke-width:2px
    
    class Main,Home mainFlow
    class Login,Signup authFlow
    class AdminMain adminFlow
    class ProductMgmt,ProductList,ProductAdd,ProductEdit,ProductDelete productFlow
    class InventoryMgmt,InventoryList,InventoryAdd,InventoryModify inventoryFlow
    class Customer,CustomerSearch customerFlow

# 데이터 흐름 다이어그램 

graph LR
    %% 사용자 입력
    User["사용자 입력"]
    
    %% View 계층
    Views["View Layer<br/>(BaseScreenView)"]
    
    %% Controller 계층
    Controllers["Controller Layer<br/>(BaseController)"]
    
    %% Model 계층
    Models["Model Layer<br/>(User, Product, Inventory)"]
    
    %% Data 계층
    CsvRepo["CsvRepository<br/>(Data Access)"]
    
    %% 파일 시스템
    CsvFiles["CSV Files<br/>(user.csv, product.csv, inventory.csv)"]
    
    %% 데이터 흐름
    User --> Views
    Views --> Controllers
    Controllers --> Models
    Controllers --> CsvRepo
    CsvRepo --> CsvFiles
    
    %% 응답 흐름
    CsvFiles --> CsvRepo
    CsvRepo --> Controllers
    Models --> Controllers
    Controllers --> Views
    Views --> User
    
    %% 스타일링
    classDef userLayer fill:#ffcdd2,stroke:#f44336,stroke-width:2px
    classDef viewLayer fill:#c8e6c9,stroke:#4caf50,stroke-width:2px
    classDef controllerLayer fill:#bbdefb,stroke:#2196f3,stroke-width:2px
    classDef modelLayer fill:#fff3c4,stroke:#ffeb3b,stroke-width:2px
    classDef dataLayer fill:#f8bbd9,stroke:#e91e63,stroke-width:2px
    classDef fileLayer fill:#d1c4e9,stroke:#9c27b0,stroke-width:2px
    
    class User userLayer
    class Views viewLayer
    class Controllers controllerLayer
    class Models modelLayer
    class CsvRepo dataLayer
    class CsvFiles fileLayer