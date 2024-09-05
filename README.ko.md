# ReadProcessMemory Demo

이 저장소에는 Windows에서 `ReadProcessMemory` 함수를 사용하여 프로세스 메모리를 읽는 연습 코드가 포함되어 있습니다. 두 개의 간단한 프로그램이 포함되어 있습니다:

1. **Dummy Program**: 정수형 변수(`varInt`)를 선언하고 해당 변수의 메모리 주소와 값을 출력하는 콘솔 애플리케이션입니다.
2. **Memory Reader**: `ReadProcessMemory`를 사용하여 Dummy Program에서 `varInt`의 값을 읽는 프로그램입니다.

## 사용 방법

### 1단계: Dummy Program 컴파일 및 실행
1. `DummyProgram.cpp` 파일을 빌드하고 실행합니다.
2. 프로그램은 `varInt`, `varString`, `arrChar`, 그리고 포인터들의 메모리 주소와 값을 출력합니다.
3. 프로그램은 계속 실행되며, 프로세스 ID(PID)와 메모리 주소를 확인할 수 있습니다:
   - **프로세스 ID**: 이 값은 `ReadProcessMemory` 프로그램을 실행할 때 사용됩니다.
   - 나중에 사용할 `varInt`의 메모리 주소를 기록해 둡니다.

### 2단계: Memory Reader 컴파일 및 실행
1. `ReadProcessMemory.cpp` 파일을 빌드하고 실행합니다.
2. 프로그램 실행 후, **Dummy Program의 PID**를 입력합니다.
3. 그런 다음, `varInt`의 메모리 주소를 16진수로 입력합니다(더미 프로그램에서 출력된 값을 사용).
4. 프로그램은 `ReadProcessMemory` 함수를 사용하여 Dummy Program의 메모리에서 `varInt`의 값을 읽고 결과를 출력합니다.

## 파일

- `DummyProgram.cpp`: Dummy Program의 소스 코드입니다.
- `ReadProcessMemory.cpp`: Memory Reader의 소스 코드입니다.

## 주의 사항

이 코드는 교육 목적으로만 사용해야 합니다. 다른 프로세스의 메모리를 읽거나 수정하는 것은 부적절하게 사용될 경우 유해하거나 불법일 수 있습니다.
