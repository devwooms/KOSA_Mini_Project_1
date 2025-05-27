# 컴파일러 및 옵션
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# 제외할 파일들
EXCLUDE_PATHS = ./admin/temp/* ./admin/test.cpp

# 모든 .cpp 파일을 재귀적으로 수집 (제외 패턴 적용)
SRCS := $(shell find . -name '*.cpp' $(foreach path,$(EXCLUDE_PATHS),! -path '$(path)'))

# .cpp → .o 변환
OBJS := $(SRCS:.cpp=.o)

# 최종 실행파일 이름
TARGET = mytest

# 기본 빌드 규칙
all: $(TARGET)

# 링크 단계
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

# 컴파일 단계: .cpp → .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 정리
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean