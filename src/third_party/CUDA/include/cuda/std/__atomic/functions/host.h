%  ò$  ó#  ô"  õ!  ö   Û  Ü    N                      M      8  <  >  ?  @
  C	  G  H  I  J  K  LÖJÌøø0´ ´ 
È  QÔ  ¢ÐøÌ  `¼  ]  Q   
À  oÐøÂÌø¸  Qø¤øøøø|Ì  oÐøhÌ  ]   Ì FÌ <ÈÌ 2  oÌ  `Ä  ]  Q  ¡   þ 
¼  PØ  ¤Ô  pÐø ´Ìø ªÈ  ]  Qø ø ø xÌ  oÐ 2Ì  ]  Q  
  PØ  SÔø Ðø Ìø 
  QÔ  ¢Ð  b  k  i  N  6  Ì     ¸à  ®Ø  N¤  R à  XÜ  bÔ  rÐ   ¢ 2Ø¢ (à¢ Ü   ¢ 
Ø  ]Ø$ xÀ 
Ü  kÔ$ ZÐÞ 
´   $ 2¬$ (  XÔ$ Ð     `Ø  kÔ    Ô   Ð      Ø   x  XØ   dÔ   ZÐ      FØ   <Ô      (Ø   Ô  NÐ     _  ^  ]  \  [  Z       7s|ÐBoãQl3¶pSQLite format 3   @         f   Ã                                                     .fêø  èÇ&
ý
Ý\Æ>ºÒ                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             J+[triggerTrgSymbolInsertSymbolCREATE TRIGGER TrgSymbolInsert AFTER INSERT ON Symbol
BEGIN
    INSERT INTO SymbolCompletion(rowid, UnqualifiedName) 
    VALUES (new.Id, new.UnqualifiedName);
ENDe+triggerTrgSymbolDeleteSymbolCREATE TRIGGER TrgSymbolDelete AFTER DELETE ON Symbol
BEGIN
    INSERT INTO SymbolCompletion(SymbolCompletion, rowid, UnqualifiedName)
    VALUES ('delete', old.Id, old.UnqualifiedName);
END;;tableSymbolCompletion_configSymbolCompletion_configCREATE TABLE 'SymbolCompletion_config'(k PRIMARY KEY, v) WITHOUT ROWID==tableSymbolCompletion_docsizeSymbolCompletion_docsizeCREATE TABLE 'SymbolCompletion_docsize'(id INTEGER PRIMARY KEY, sz BLOB)
55ItableSymbolCompletion_idxSymbolCompletion_idx
CREATE TABLE 'SymbolCompletion_idx'(segid, term, pgno, PRIMARY KEY(segid, term)) WITHOUT ROWID	77tableSymbolCompletion_dataSymbolCompletion_data	CREATE TABLE 'SymbolCompletion_data'(id INTEGER PRIMARY KEY, block BLOB)'--tableSymbolCompletionSymbolCompletionCREATE VIRTUAL TABLE 'SymbolCompletion' USING fts5(
    'UnqualifiedName',
    content = '', -- Creates a contentless table  to save database space: https://www.sqlite.org/fts5.html#external_content_and_contentless_tables
    tokenize = "trigram" -- Built-in tokenizer that allows FTS5 to support more general substring matching: https://www.sqlite.org/fts5.html#tokenizers
)t?indexIX_Symbol_UnqualifiedNameSymbolCREATE INDEX 'IX_Symbol_UnqualifiedName' ON 'Symbol' ('UnqualifiedName')5GindexIX_Symbol_DocumentIdSymbolCREATE INDEX 'IX_Symbol_DocumentId' ON 'Symbol' ('DocumentId', 'ExtentStart', 'ExtentLength')tableSymbolSymbolCREATE TABLE 'Symbol' (
    'Id' INTEGER PRIMARY KEY AUTOINCREMENT,
    'DocumentId' INTEGER,
    'FullyQualifiedName' VARCHAR(500) NOT NULL,
    'UnqualifiedName' VARCHAR(500) COLLATE NOCASE NOT NULL,
    'CommentStart' INTEGER NOT NULL,
    'CommentLength' INTEGER NOT NULL,
    'NameStart' INTEGER NOT NULL,
    'NameLength' INTEGER NOT NULL,
    'BodyStart' INTEGER NOT NULL,
    'BodyLength' INTEGER NOT NULL,
    'ExtentStart' INTEGER NOT NULL,
    'ExtentLength' INTEGER NOT NULL,
    'SymbolKind' INTEGER NOT NULL,
    'MethodSignature' VARCHAR(500),
    FOREIGN KEY(DocumentId) REFERENCES Document(Id) ON DELETE CASCADE
)n5indexIX_Document_FilePathDocumentCREATE UNIQUE INDEX 'IX_Document_FilePath' ON 'Document' ('FilePath')P++Ytablesqlite_sequencesqlite_sequenceCREATE TABLE sqlite_sequence(name,seq)\tableDocumentDocumentCREATE TABLE 'Document' (
    'Id' INTEGER PRIMARY KEY AUTOINCREMENT,
    'FilePath' VARCHAR(500) NOT NULL COLLATE NOCASE,
    'LastWriteTimeUtc' INTEGER NOT NULL,
    UNIQUE(FilePath)
)/C indexsqlite_autoindex_Document_1Document          "    7s|ÐBo1YôÒg1

 2# °EÜq 3ÇC#
Ý
©
w
=	Æ		W	'×T!é³|G×¯gË,Ô4êSµl!Ù                                                                                                                  DF:\Win_x64-sysMonitor\Project1\LibreHardwareMonitorBridge.cpp)ükWF:\Win_x64-sysMonitor\Project1\Project1\x64\Debug\.NETFramework,Version=v4.7.2.AssemblyAttributes.cpp)BIF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\sm_70_rt.hpp"GF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\sm_70_rt.h!JF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\sm_100_rt.hppHF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\sm_100_rt.hOF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\math_functions.hpp ´MF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\math_functions.h ³KF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\host_defines.h JF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\host_config.h IF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\func_macro.h P#F:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\device_functions.hppeNF:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\device_functions.hdW1F:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\device_double_functions.hppcU-F:\Win_x64-sysMonitor\src\third_party\CUDA\include\crt\device_double_functions.hbHF:\Win_x64-sysMonitor\src\t