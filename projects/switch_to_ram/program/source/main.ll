; ModuleID = '../switch_to_ram/program/source/main.c'
source_filename = "../switch_to_ram/program/source/main.c"
target datalayout = "E-m:e-p:32:32-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "armebv7r-none--eabi"

%struct.gioPort = type { i32, i32, i32, i32, i32, i32, i32, i32 }
%struct.gioBase = type { i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32 }

; Function Attrs: noinline nounwind optnone
define i32 @main() #0 !dbg !42 {
  %1 = alloca i32, align 4
  %2 = alloca %struct.gioPort*, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store volatile i32 1, i32* getelementptr inbounds (%struct.gioBase, %struct.gioBase* inttoptr (i32 -541696 to %struct.gioBase*), i32 0, i32 0), align 4, !dbg !46
  store volatile i32 255, i32* getelementptr inbounds (%struct.gioBase, %struct.gioBase* inttoptr (i32 -541696 to %struct.gioBase*), i32 0, i32 5), align 4, !dbg !47
  store volatile i32 255, i32* getelementptr inbounds (%struct.gioBase, %struct.gioBase* inttoptr (i32 -541696 to %struct.gioBase*), i32 0, i32 7), align 4, !dbg !48
  store volatile i32 0, i32* getelementptr inbounds (%struct.gioPort, %struct.gioPort* inttoptr (i32 -541644 to %struct.gioPort*), i32 0, i32 2), align 4, !dbg !49
  store volatile i32 4, i32* getelementptr inbounds (%struct.gioPort, %struct.gioPort* inttoptr (i32 -541644 to %struct.gioPort*), i32 0, i32 0), align 4, !dbg !50
  store volatile i32 0, i32* getelementptr inbounds (%struct.gioPort, %struct.gioPort* inttoptr (i32 -541644 to %struct.gioPort*), i32 0, i32 5), align 4, !dbg !51
  store volatile i32 0, i32* getelementptr inbounds (%struct.gioPort, %struct.gioPort* inttoptr (i32 -541644 to %struct.gioPort*), i32 0, i32 7), align 4, !dbg !52
  store volatile i32 0, i32* getelementptr inbounds (%struct.gioPort, %struct.gioPort* inttoptr (i32 -541644 to %struct.gioPort*), i32 0, i32 6), align 4, !dbg !53
  call void @llvm.dbg.declare(metadata %struct.gioPort** %2, metadata !54, metadata !DIExpression()), !dbg !57
  store %struct.gioPort* inttoptr (i32 -541644 to %struct.gioPort*), %struct.gioPort** %2, align 4, !dbg !57
  call void @llvm.dbg.declare(metadata i32* %3, metadata !58, metadata !DIExpression()), !dbg !59
  store i32 2, i32* %3, align 4, !dbg !59
  br label %5, !dbg !60

; <label>:5:                                      ; preds = %0, %31
  %6 = load %struct.gioPort*, %struct.gioPort** %2, align 4, !dbg !61
  %7 = getelementptr inbounds %struct.gioPort, %struct.gioPort* %6, i32 0, i32 1, !dbg !64
  %8 = load volatile i32, i32* %7, align 4, !dbg !64
  %9 = load i32, i32* %3, align 4, !dbg !65
  %10 = shl i32 1, %9, !dbg !66
  %11 = and i32 %8, %10, !dbg !67
  %12 = icmp ne i32 %11, 0, !dbg !68
  br i1 %12, label %13, label %18, !dbg !69

; <label>:13:                                     ; preds = %5
  %14 = load i32, i32* %3, align 4, !dbg !70
  %15 = shl i32 1, %14, !dbg !72
  %16 = load %struct.gioPort*, %struct.gioPort** %2, align 4, !dbg !73
  %17 = getelementptr inbounds %struct.gioPort, %struct.gioPort* %16, i32 0, i32 4, !dbg !74
  store volatile i32 %15, i32* %17, align 4, !dbg !75
  br label %23, !dbg !76

; <label>:18:                                     ; preds = %5
  %19 = load i32, i32* %3, align 4, !dbg !77
  %20 = shl i32 1, %19, !dbg !79
  %21 = load %struct.gioPort*, %struct.gioPort** %2, align 4, !dbg !80
  %22 = getelementptr inbounds %struct.gioPort, %struct.gioPort* %21, i32 0, i32 3, !dbg !81
  store volatile i32 %20, i32* %22, align 4, !dbg !82
  br label %23

; <label>:23:                                     ; preds = %18, %13
  call void @llvm.dbg.declare(metadata i32* %4, metadata !83, metadata !DIExpression()), !dbg !86
  store volatile i32 0, i32* %4, align 4, !dbg !86
  br label %24, !dbg !87

; <label>:24:                                     ; preds = %28, %23
  %25 = load volatile i32, i32* %4, align 4, !dbg !88
  %26 = icmp slt i32 %25, 1000000, !dbg !90
  br i1 %26, label %27, label %31, !dbg !91

; <label>:27:                                     ; preds = %24
  br label %28, !dbg !91

; <label>:28:                                     ; preds = %27
  %29 = load volatile i32, i32* %4, align 4, !dbg !92
  %30 = add nsw i32 %29, 1, !dbg !92
  store volatile i32 %30, i32* %4, align 4, !dbg !92
  br label %24, !dbg !93, !llvm.loop !94

; <label>:31:                                     ; preds = %24
  br label %5, !dbg !60, !llvm.loop !96
                                                  ; No predecessors!
  %33 = load i32, i32* %1, align 4, !dbg !98
  ret i32 %33, !dbg !98
}

; Function Attrs: nounwind readnone speculatable
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

attributes #0 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="cortex-r4" "target-features"="+dsp,+hwdiv,+soft-float,+strict-align,-crc,-crypto,-dotprod,-hwdiv-arm,-neon,-ras,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #1 = { nounwind readnone speculatable }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!37, !38, !39, !40}
!llvm.ident = !{!41}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, retainedTypes: !3)
!1 = !DIFile(filename: "../switch_to_ram/program/source/main.c", directory: "/home/jh/Documents/bachelorarbeit/projects/load_time_diversity")
!2 = !{}
!3 = !{!4, !10, !24}
!4 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !5, size: 32)
!5 = !DIDerivedType(tag: DW_TAG_typedef, name: "gioBASE_t", file: !1, line: 25, baseType: !6)
!6 = !DIDerivedType(tag: DW_TAG_volatile_type, baseType: !7)
!7 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "gioBase", file: !1, line: 10, size: 416, elements: !8)
!8 = !{!9, !12, !13, !14, !15, !16, !17, !18, !19, !20, !21, !22, !23}
!9 = !DIDerivedType(tag: DW_TAG_member, name: "GCR0", scope: !7, file: !1, line: 12, baseType: !10, size: 32)
!10 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint32_t", file: !1, line: 1, baseType: !11)
!11 = !DIBasicType(name: "long unsigned int", size: 32, encoding: DW_ATE_unsigned)
!12 = !DIDerivedType(tag: DW_TAG_member, name: "rsvd", scope: !7, file: !1, line: 13, baseType: !10, size: 32, offset: 32)
!13 = !DIDerivedType(tag: DW_TAG_member, name: "INTDET", scope: !7, file: !1, line: 14, baseType: !10, size: 32, offset: 64)
!14 = !DIDerivedType(tag: DW_TAG_member, name: "POL", scope: !7, file: !1, line: 15, baseType: !10, size: 32, offset: 96)
!15 = !DIDerivedType(tag: DW_TAG_member, name: "ENASET", scope: !7, file: !1, line: 16, baseType: !10, size: 32, offset: 128)
!16 = !DIDerivedType(tag: DW_TAG_member, name: "ENACLR", scope: !7, file: !1, line: 17, baseType: !10, size: 32, offset: 160)
!17 = !DIDerivedType(tag: DW_TAG_member, name: "LVLSET", scope: !7, file: !1, line: 18, baseType: !10, size: 32, offset: 192)
!18 = !DIDerivedType(tag: DW_TAG_member, name: "LVLCLR", scope: !7, file: !1, line: 19, baseType: !10, size: 32, offset: 224)
!19 = !DIDerivedType(tag: DW_TAG_member, name: "FLG", scope: !7, file: !1, line: 20, baseType: !10, size: 32, offset: 256)
!20 = !DIDerivedType(tag: DW_TAG_member, name: "OFF1", scope: !7, file: !1, line: 21, baseType: !10, size: 32, offset: 288)
!21 = !DIDerivedType(tag: DW_TAG_member, name: "OFF2", scope: !7, file: !1, line: 22, baseType: !10, size: 32, offset: 320)
!22 = !DIDerivedType(tag: DW_TAG_member, name: "EMU1", scope: !7, file: !1, line: 23, baseType: !10, size: 32, offset: 352)
!23 = !DIDerivedType(tag: DW_TAG_member, name: "EMU2", scope: !7, file: !1, line: 24, baseType: !10, size: 32, offset: 384)
!24 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !25, size: 32)
!25 = !DIDerivedType(tag: DW_TAG_typedef, name: "gioPORT_t", file: !1, line: 39, baseType: !26)
!26 = !DIDerivedType(tag: DW_TAG_volatile_type, baseType: !27)
!27 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "gioPort", file: !1, line: 29, size: 256, elements: !28)
!28 = !{!29, !30, !31, !32, !33, !34, !35, !36}
!29 = !DIDerivedType(tag: DW_TAG_member, name: "DIR", scope: !27, file: !1, line: 31, baseType: !10, size: 32)
!30 = !DIDerivedType(tag: DW_TAG_member, name: "DIN", scope: !27, file: !1, line: 32, baseType: !10, size: 32, offset: 32)
!31 = !DIDerivedType(tag: DW_TAG_member, name: "DOUT", scope: !27, file: !1, line: 33, baseType: !10, size: 32, offset: 64)
!32 = !DIDerivedType(tag: DW_TAG_member, name: "DSET", scope: !27, file: !1, line: 34, baseType: !10, size: 32, offset: 96)
!33 = !DIDerivedType(tag: DW_TAG_member, name: "DCLR", scope: !27, file: !1, line: 35, baseType: !10, size: 32, offset: 128)
!34 = !DIDerivedType(tag: DW_TAG_member, name: "PDR", scope: !27, file: !1, line: 36, baseType: !10, size: 32, offset: 160)
!35 = !DIDerivedType(tag: DW_TAG_member, name: "PULDIS", scope: !27, file: !1, line: 37, baseType: !10, size: 32, offset: 192)
!36 = !DIDerivedType(tag: DW_TAG_member, name: "PSL", scope: !27, file: !1, line: 38, baseType: !10, size: 32, offset: 224)
!37 = !{i32 2, !"Dwarf Version", i32 4}
!38 = !{i32 2, !"Debug Info Version", i32 3}
!39 = !{i32 1, !"wchar_size", i32 4}
!40 = !{i32 1, !"min_enum_size", i32 4}
!41 = !{!"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"}
!42 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 44, type: !43, isLocal: false, isDefinition: true, scopeLine: 44, isOptimized: false, unit: !0, variables: !2)
!43 = !DISubroutineType(types: !44)
!44 = !{!45}
!45 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!46 = !DILocation(line: 46, column: 17, scope: !42)
!47 = !DILocation(line: 47, column: 17, scope: !42)
!48 = !DILocation(line: 48, column: 17, scope: !42)
!49 = !DILocation(line: 53, column: 17, scope: !42)
!50 = !DILocation(line: 63, column: 17, scope: !42)
!51 = !DILocation(line: 73, column: 17, scope: !42)
!52 = !DILocation(line: 83, column: 17, scope: !42)
!53 = !DILocation(line: 93, column: 20, scope: !42)
!54 = !DILocalVariable(name: "port", scope: !42, file: !1, line: 102, type: !55)
!55 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !56, size: 32)
!56 = !DIDerivedType(tag: DW_TAG_volatile_type, baseType: !25)
!57 = !DILocation(line: 102, column: 24, scope: !42)
!58 = !DILocalVariable(name: "bit", scope: !42, file: !1, line: 103, type: !10)
!59 = !DILocation(line: 103, column: 12, scope: !42)
!60 = !DILocation(line: 105, column: 2, scope: !42)
!61 = !DILocation(line: 106, column: 8, scope: !62)
!62 = distinct !DILexicalBlock(scope: !63, file: !1, line: 106, column: 7)
!63 = distinct !DILexicalBlock(scope: !42, file: !1, line: 105, column: 12)
!64 = !DILocation(line: 106, column: 14, scope: !62)
!65 = !DILocation(line: 106, column: 47, scope: !62)
!66 = !DILocation(line: 106, column: 44, scope: !62)
!67 = !DILocation(line: 106, column: 18, scope: !62)
!68 = !DILocation(line: 106, column: 53, scope: !62)
!69 = !DILocation(line: 106, column: 7, scope: !63)
!70 = !DILocation(line: 108, column: 33, scope: !71)
!71 = distinct !DILexicalBlock(scope: !62, file: !1, line: 107, column: 3)
!72 = !DILocation(line: 108, column: 30, scope: !71)
!73 = !DILocation(line: 108, column: 4, scope: !71)
!74 = !DILocation(line: 108, column: 10, scope: !71)
!75 = !DILocation(line: 108, column: 15, scope: !71)
!76 = !DILocation(line: 109, column: 3, scope: !71)
!77 = !DILocation(line: 112, column: 33, scope: !78)
!78 = distinct !DILexicalBlock(scope: !62, file: !1, line: 111, column: 3)
!79 = !DILocation(line: 112, column: 30, scope: !78)
!80 = !DILocation(line: 112, column: 4, scope: !78)
!81 = !DILocation(line: 112, column: 10, scope: !78)
!82 = !DILocation(line: 112, column: 15, scope: !78)
!83 = !DILocalVariable(name: "j", scope: !84, file: !1, line: 114, type: !85)
!84 = distinct !DILexicalBlock(scope: !63, file: !1, line: 114, column: 3)
!85 = !DIDerivedType(tag: DW_TAG_volatile_type, baseType: !45)
!86 = !DILocation(line: 114, column: 21, scope: !84)
!87 = !DILocation(line: 114, column: 8, scope: !84)
!88 = !DILocation(line: 114, column: 28, scope: !89)
!89 = distinct !DILexicalBlock(scope: !84, file: !1, line: 114, column: 3)
!90 = !DILocation(line: 114, column: 30, scope: !89)
!91 = !DILocation(line: 114, column: 3, scope: !84)
!92 = !DILocation(line: 114, column: 40, scope: !89)
!93 = !DILocation(line: 114, column: 3, scope: !89)
!94 = distinct !{!94, !91, !95}
!95 = !DILocation(line: 114, column: 43, scope: !84)
!96 = distinct !{!96, !60, !97}
!97 = !DILocation(line: 116, column: 2, scope: !42)
!98 = !DILocation(line: 124, column: 1, scope: !42)
